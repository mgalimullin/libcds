/*
    This file is a part of libcds - Concurrent Data Structures library

    (C) Copyright Maxim Khizhinsky (libcds.dev@gmail.com) 2006-2016

    Source code repo: http://github.com/khizmax/libcds/
    Download: http://sourceforge.net/projects/libcds/files/
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     
*/

#ifndef CDSLIB_CONTAINER_FCUNORDEREDSET_H
#define CDSLIB_CONTAINER_FCUNORDEREDSET_H

#include <cds/algo/flat_combining.h>
#include <cds/algo/elimination_opt.h>
#include <unordered_set>

namespace cds { namespace container {

    /// FCUnorderedSet related definitions
    /** @ingroup cds_nonintrusive_helper
    */
    namespace fcunordered_set {

        /// FCUnorderedSet internal statistics
        template <typename Counter = cds::atomicity::event_counter >
        struct stat: public cds::algo::flat_combining::stat<Counter>
        {
            using flat_combining_stat = cds::algo::flat_combining::stat<Counter>; ///< Flat-combining statistics
            using counter_type        = typename flat_combining_stat::counter_type;        ///< Counter type

            counter_type    m_nInsert     ;   ///< Count of Insert operations
            counter_type    m_nErase      ;   ///< Count of Erase operations
            counter_type    m_nFind       ;   ///< Count of Find operations

            //@cond
            void onInsert(){ ++m_nInsert; }
            void onErase (){ ++m_nErase;  }
            void onFind  (){ ++m_nFind;   }
            //@endcond
        };

        /// FCUnorderedSet dummy statistics, no overhead
        struct empty_stat: public cds::algo::flat_combining::empty_stat
        {
            //@cond
            void onInsert(){}
            void onErase (){}
            void onFind  (){}
            //@endcond
        };

        /// FCUnorderedSet type traits
        struct traits: public cds::algo::flat_combining::traits
        {
            typedef empty_stat      stat;   ///< Internal statistics
            static CDS_CONSTEXPR const bool enable_elimination = false; ///< Enable \ref cds_elimination_description "elimination"
        };

        /// Metafunction converting option list to traits
        /**
            \p Options are:
            - \p opt::lock_type - mutex type, default is \p cds::sync::spin
            - \p opt::back_off - back-off strategy, defalt is \p cds::backoff::delay_of<2>
            - \p opt::allocator - allocator type, default is \ref CDS_DEFAULT_ALLOCATOR
            - \p opt::stat - internal statistics, possible type: \p fcunordered_set::stat, \p fcunordered_set::empty_stat (the default)
            - \p opt::memory_model - C++ memory ordering model.
                List of all available memory ordering see \p opt::memory_model.
                Default is \p cds::opt::v:relaxed_ordering
            - \p opt::enable_elimination - enable/disable operation \ref cds_elimination_description "elimination"
                By default, the elimination is disabled. For unordered_set, the elimination is possible if the unordered_set
                is empty.
        */
        template <typename... Options>
        struct make_traits {
#   ifdef CDS_DOXYGEN_INVOKED
            typedef implementation_defined type ;   ///< Metafunction result
#   else
            typedef typename cds::opt::make_options<
                typename cds::opt::find_type_traits< traits, Options... >::type
                ,Options...
            >::type   type;
#   endif
        };

    } // namespace fcunordered_set


    template <typename T,
        template <class, class>  class WaitStrategy = cds::algo::flat_combining::WaitBakkOffStrategy,
        class Hash = std::hash<T>,
        class KeyEqual = std::equal_to<T>,
        class Set = std::unordered_set<T, Hash, KeyEqual>,
        class Traits = fcunordered_set::traits
    >
    class FCUnorderedSet
#ifndef CDS_DOXYGEN_INVOKED
        : public cds::algo::flat_combining::container
#endif
    {
    public:
        using value_type = T;     ///< Value type
        using set_type = Set;     ///< Sequential map class
        using traits = Traits;    ///< Map type traits

        using stat = typename traits::stat  ;   ///< Internal statistics type
        static CDS_CONSTEXPR const bool c_bEliminationEnabled = traits::enable_elimination; ///< \p true if elimination is enabled

    protected:
        //@cond
        /// unordered_set operation IDs
        enum fc_operation {
            op_insert = cds::algo::flat_combining::req_Operation,
            op_erase,
            op_find,
            op_clear
        };

        /// Flat combining publication list record
        struct fc_record : public cds::algo::flat_combining::publication_record
        {
            union {
                value_type const *  pValInsert;  ///< Value to insert
                value_type const *  pValErase;  ///< Value to erase
                value_type const *  pValFind;    ///< Flag to find
            };
            bool            bEmpty; ///< \p true if the unordered_set is empty
            bool 			bFindSuccess;
        };
        //@endcond

        /// Flat combining kernel
        using fc_kernel = cds::algo::flat_combining::kernel< fc_record, traits, WaitStrategy >;

    protected:
        //@cond
        fc_kernel m_FlatCombining;
        set_type  m_Set;
        //@endcond

    public:
        /// Initializes empty unordered_set object
        FCUnorderedSet()
        {}

        /// Initializes empty unordered_set object and gives flat combining parameters
        FCUnorderedSet(
            unsigned int nCompactFactor     ///< Flat combining: publication list compacting factor
            , unsigned int nCombinePassCount ///< Flat combining: number of combining passes for combiner thread
            )
            : m_FlatCombining(nCompactFactor, nCombinePassCount)
        {}

        /// Inserts a new element at the unordered_set
        /**
        The content of the new element initialized to a copy of \p val.

        The function always returns \p true
        */
        bool insert(value_type const& val)
        {
            fc_record * pRec = m_FlatCombining.acquire_record();
            pRec->pValInsert = &val;

            if (c_bEliminationEnabled)
                m_FlatCombining.batch_combine(op_insert, pRec, *this);
            else
                m_FlatCombining.combine(op_insert, pRec, *this);

            assert(pRec->is_done());
            m_FlatCombining.release_record(pRec);
            m_FlatCombining.internal_statistics().onInsert();
            return true;
        }

        /// Removes the element from the unordered_set
        /**
        \p val value of the elements to remove
        */
        bool erase(value_type const& val)
        {
            fc_record * pRec = m_FlatCombining.acquire_record();
            pRec->pValErase = &val;

            if (c_bEliminationEnabled)
                m_FlatCombining.batch_combine(op_erase, pRec, *this);
            else
                m_FlatCombining.combine(op_erase, pRec, *this);

            assert(pRec->is_done());
            m_FlatCombining.release_record(pRec);

            m_FlatCombining.internal_statistics().onErase();
            return !pRec->bEmpty;
        }

        bool find(value_type const& val)
        {
            fc_record * pRec = m_FlatCombining.acquire_record();
            pRec->pValFind = &val;

            if (c_bEliminationEnabled)
                m_FlatCombining.batch_combine(op_find, pRec, *this);
            else
                m_FlatCombining.combine(op_find, pRec, *this);

            assert(pRec->is_done());
            m_FlatCombining.release_record(pRec);

            m_FlatCombining.internal_statistics().onFind();
            return pRec->bFindSuccess && !pRec->bEmpty;
        }

        /// Clears the unordered_set
        void clear()
        {
            fc_record * pRec = m_FlatCombining.acquire_record();

            if (c_bEliminationEnabled)
                m_FlatCombining.batch_combine(op_clear, pRec, *this);
            else
                m_FlatCombining.combine(op_clear, pRec, *this);

            assert(pRec->is_done());
            m_FlatCombining.release_record(pRec);
        }

        /// Returns the number of elements in the unordered_set.
        /**
        Note that <tt>size() == 0</tt> is not mean that the unordered_set is empty because
        combining record can be in process.
        To check emptiness use \ref empty function.
        */
        size_t size() const
        {
            return m_Set.size();
        }

        /// Checks if the unordered_set is empty
        /**
        If the combining is in process the function waits while combining done.
        */
        bool empty() const
        {
            m_FlatCombining.wait_while_combining();
            return m_Set.empty();
        }

        /// Internal statistics
        stat const& statistics() const
        {
            return m_FlatCombining.statistics();
        }

    public: // flat combining cooperation, not for direct use!
        //@cond
        /// Flat combining supporting function. Do not call it directly!
        /**
        The function is called by \ref cds::algo::flat_combining::kernel "flat combining kernel"
        object if the current thread becomes a combiner. Invocation of the function means that
        the unordered_set should perform an action recorded in \p pRec.
        */
        void fc_apply(fc_record * pRec)
        {
            assert(pRec);

            switch (pRec->op()) {
            case op_insert:
                assert(pRec->pValInsert);
                m_Set.insert(*(pRec->pValInsert));
                break;
            case op_erase:
                assert(pRec->pValErase);
                pRec->bEmpty = m_Set.empty();
                m_Set.erase(*(pRec->pValErase));
                break;
            case op_find:
                assert(pRec->pValFind);
                pRec->bEmpty = m_Set.empty();
                pRec->bFindSuccess = m_Set.find(*(pRec->pValFind)) != m_Set.end();
                break;
            case op_clear:
                m_Set.clear();
                break;
            default:
                assert(false);
                break;
            }
        }

        //@endcond
    };

}} // namespace cds::container

#endif // #ifndef CDSLIB_CONTAINER_FCUNORDEREDSET_H
