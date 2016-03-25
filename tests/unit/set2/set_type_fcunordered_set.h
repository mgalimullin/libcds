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

#ifndef CDSUNIT_SET_TYPE_UNORDERED_SET_H
#define CDSUNIT_SET_TYPE_UNORDERED_SET_H

#include "set2/set_type.h"
#include <cds/container/fcunordered_set.h>

namespace set2 {

#define array_size  100000
	struct HeavyValue {
		int    nNo;
		static volatile int pop_buff[array_size];

		HeavyValue() : nNo(0) {}
		HeavyValue(int n) : nNo(n) {
			for (int i = 0; i < array_size; ++i)
				this->pop_buff[i] = static_cast<int>(std::sqrt(pop_buff[i]));
		}

		HeavyValue(const HeavyValue &other):nNo(other.nNo){
			for (int i = 0; i < array_size; ++i)
				this->pop_buff[i] = static_cast<int>(std::sqrt(other.pop_buff[i]));
		}
		int getNo() const { return  nNo; }

		bool operator<( const HeavyValue& other){
			return nNo < other.nNo;
		}

		bool operator==( const HeavyValue& other){
			return nNo == other.nNo;
		}
	};
	volatile int HeavyValue::pop_buff[]= {};
#undef array_size

	class HeavyValueHash {
	public:
	    size_t operator()(const HeavyValue &s) const
	    {
	    	return std::hash<int>()(s.nNo);
	    }
	};
	class HeavyValueKeyEqualFn {
	public:
		bool operator()(const HeavyValue& t1, const HeavyValue& t2) const {
			return (t1.nNo == t2.nNo);
		}
	};
	template <typename T,
			  template <class, class>  class WaitStrategy>
    class FCUnorderedSet : public cc::FCUnorderedSet< T,  WaitStrategy, HeavyValueHash, HeavyValueKeyEqualFn>
    {
		typedef cc::FCUnorderedSet< T, WaitStrategy, HeavyValueHash, HeavyValueKeyEqualFn> base_class;

	public:
		template <class Config>
		FCUnorderedSet( Config const& cfg )
			: base_class()
		{}

		// for testing
		static CDS_CONSTEXPR bool const c_bExtractSupported = true;
		static CDS_CONSTEXPR bool const c_bLoadFactorDepended = true;
		static CDS_CONSTEXPR bool const c_bEraseExactKey = false;
    };

    struct tag_FCUnorderedSet;

        template <typename Key, typename Val>
        struct set_type< tag_FCUnorderedSet, Key, Val >: public set_type_base< Key, Val >
        {
            using base_class = set_type_base< Key, Val >;
            using key_val 	 = typename base_class::key_val;
            using compare 	 = typename base_class::compare;
            using less 		 = typename base_class::less;
            using hash 		 = typename base_class::hash;

            // ***************************************************************************
            using FCUnorderedSet_HeavyValue_BackOff = FCUnorderedSet<HeavyValue, cds::algo::flat_combining::WaitBakkOffStrategy>;
            using FCUnorderedSet_HeavyValue_Bare 	 = FCUnorderedSet<HeavyValue, cds::algo::flat_combining::BareWaitStrategy>;
            using FCUnorderedSet_HeavyValue_MMMCV 	 = FCUnorderedSet<HeavyValue, cds::algo::flat_combining::WaitStrategyMultMutexMultCondVar>;
            using FCUnorderedSet_HeavyValue_OMOCV 	 = FCUnorderedSet<HeavyValue, cds::algo::flat_combining::WaitOneMutexOneCondVarStrategy>;

        };


} // namespace set2

#endif // #ifndef CDSUNIT_SET_TYPE_UNORDERED_SET_H
