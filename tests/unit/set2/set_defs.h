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

//********************************************************************
// FCUnorderdSet
#define CDSUNIT_DECLARE_FCUnorderedSet1  \
    TEST_CASE(tag_FCUnorderedSet, FCUnorderedSet_HeavyValue_BackOff)
#define CDSUNIT_TEST_FCUnorderedSet1  \
    CPPUNIT_TEST(FCUnorderedSet_HeavyValue_BackOff)

#define CDSUNIT_DECLARE_FCUnorderedSet2  \
    TEST_CASE(tag_FCUnorderedSet, FCUnorderedSet_HeavyValue_Bare)
#define CDSUNIT_TEST_FCUnorderedSet2  \
    CPPUNIT_TEST(FCUnorderedSet_HeavyValue_Bare)\

#define CDSUNIT_DECLARE_FCUnorderedSet3  \
    TEST_CASE(tag_FCUnorderedSet, FCUnorderedSet_HeavyValue_MMMCV)
#define CDSUNIT_TEST_FCUnorderedSet3  \
    CPPUNIT_TEST(FCUnorderedSet_HeavyValue_MMMCV)

#define CDSUNIT_DECLARE_FCUnorderedSet4  \
    TEST_CASE(tag_FCUnorderedSet, FCUnorderedSet_HeavyValue_OMOCV)
#define CDSUNIT_TEST_FCUnorderedSet4  \
    CPPUNIT_TEST(FCUnorderedSet_HeavyValue_OMOCV)

//********************************************************************
// StdSet
#define CDSUNIT_DECLARE_StdSet \
    TEST_CASE( tag_StdSet, StdSet_Spin) \
    TEST_CASE( tag_StdSet, StdSet_Mutex) \
    TEST_CASE( tag_StdSet, StdHashSet_Spin)

#define CDSUNIT_TEST_StdSet \
    CPPUNIT_TEST(StdSet_Spin) \
    CPPUNIT_TEST(StdSet_Mutex) \
    CPPUNIT_TEST(StdHashSet_Spin)



//********************************************************************
// MichaelHashSet

#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
#   define CDSUNIT_DECLARE_MichaelSet_RCU_signal  \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_SHB_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_SHB_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_SHT_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_SHT_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_SHB_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_SHB_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_SHT_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_SHT_less_michaelAlloc)

#   define CDSUNIT_TEST_MichaelSet_RCU_signal  \
    CPPUNIT_TEST(MichaelSet_RCU_SHB_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_RCU_SHB_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_RCU_SHT_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_RCU_SHT_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_SHB_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_SHB_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_SHT_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_SHT_less_michaelAlloc)
#else
#   define CDSUNIT_DECLARE_MichaelSet_RCU_signal
#   define CDSUNIT_TEST_MichaelSet_RCU_signal
#endif

#define CDSUNIT_DECLARE_MichaelSet  \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_HP_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_HP_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_DHP_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_DHP_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_GPI_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_GPI_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_GPB_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_GPB_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_GPT_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_RCU_GPT_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_HP_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_HP_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_DHP_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_DHP_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_GPI_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_GPI_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_GPB_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_GPB_less_michaelAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_GPT_cmp_stdAlloc) \
    TEST_CASE(tag_MichaelHashSet, MichaelSet_Lazy_RCU_GPT_less_michaelAlloc) \
    CDSUNIT_DECLARE_MichaelSet_RCU_signal

#define CDSUNIT_TEST_MichaelSet  \
    CPPUNIT_TEST(MichaelSet_HP_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_HP_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_DHP_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_DHP_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_RCU_GPI_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_RCU_GPI_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_RCU_GPB_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_RCU_GPB_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_RCU_GPT_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_RCU_GPT_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_HP_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_HP_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_DHP_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_DHP_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_GPI_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_GPI_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_GPB_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_GPB_less_michaelAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_GPT_cmp_stdAlloc) \
    CPPUNIT_TEST(MichaelSet_Lazy_RCU_GPT_less_michaelAlloc) \
    CDSUNIT_TEST_MichaelSet_RCU_signal

//********************************************************************
// SplitListSet

#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
#   define CDSUNIT_DECLARE_SplitList_RCU_signal  \
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHB_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHB_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHB_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHB_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHB_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHB_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHT_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHT_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHT_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHT_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHT_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_SHT_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHB_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHB_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHB_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHB_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHB_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHB_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHT_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHT_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHT_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHT_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHT_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_SHT_st_less_stat)

#   define CDSUNIT_TEST_SplitList_RCU_signal  \
    CPPUNIT_TEST(SplitList_Michael_RCU_SHB_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHB_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHB_st_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHB_dyn_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHB_st_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHB_st_less_stat)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHT_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHT_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHT_st_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHT_dyn_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHT_st_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_SHT_st_less_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHB_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHB_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHB_st_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHB_dyn_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHB_st_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHB_st_less_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHT_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHT_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHT_st_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHT_dyn_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHT_st_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_SHT_st_less_stat)

#else
#   define CDSUNIT_DECLARE_SplitList_RCU_signal
#   define CDSUNIT_TEST_SplitList_RCU_signal
#endif

#define CDSUNIT_DECLARE_SplitList  \
    TEST_CASE(tag_SplitListSet, SplitList_Michael_HP_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_HP_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_HP_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_HP_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_HP_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_HP_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_DHP_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_DHP_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_DHP_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_DHP_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_DHP_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_DHP_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPI_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPI_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPI_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPI_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPI_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPI_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPB_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPB_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPB_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPB_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPB_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPB_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPT_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPT_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPT_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPT_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPT_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Michael_RCU_GPT_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_HP_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_HP_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_HP_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_HP_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_HP_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_HP_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_DHP_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_DHP_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_DHP_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_DHP_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_DHP_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_DHP_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPI_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPI_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPI_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPI_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPI_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPI_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPB_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPB_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPB_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPB_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPB_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPB_st_less_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPT_dyn_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPT_dyn_cmp_stat)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPT_st_cmp)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPT_dyn_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPT_st_less)\
    TEST_CASE(tag_SplitListSet, SplitList_Lazy_RCU_GPT_st_less_stat)\
    CDSUNIT_DECLARE_SplitList_RCU_signal

#define CDSUNIT_TEST_SplitList  \
    CPPUNIT_TEST(SplitList_Michael_HP_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Michael_HP_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Michael_HP_st_cmp)\
    CPPUNIT_TEST(SplitList_Michael_HP_dyn_less)\
    CPPUNIT_TEST(SplitList_Michael_HP_st_less)\
    CPPUNIT_TEST(SplitList_Michael_HP_st_less_stat)\
    CPPUNIT_TEST(SplitList_Michael_DHP_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Michael_DHP_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Michael_DHP_st_cmp)\
    CPPUNIT_TEST(SplitList_Michael_DHP_dyn_less)\
    CPPUNIT_TEST(SplitList_Michael_DHP_st_less)\
    CPPUNIT_TEST(SplitList_Michael_DHP_st_less_stat)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPI_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPI_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPI_st_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPI_dyn_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPI_st_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPI_st_less_stat)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPB_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPB_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPB_st_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPB_dyn_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPB_st_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPB_st_less_stat)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPT_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPT_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPT_st_cmp)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPT_dyn_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPT_st_less)\
    CPPUNIT_TEST(SplitList_Michael_RCU_GPT_st_less_stat)\
    CPPUNIT_TEST(SplitList_Lazy_HP_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_HP_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Lazy_HP_st_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_HP_dyn_less)\
    CPPUNIT_TEST(SplitList_Lazy_HP_st_less)\
    CPPUNIT_TEST(SplitList_Lazy_HP_st_less_stat)\
    CPPUNIT_TEST(SplitList_Lazy_DHP_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_HP_st_less_stat)\
    CPPUNIT_TEST(SplitList_Lazy_DHP_st_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_DHP_dyn_less)\
    CPPUNIT_TEST(SplitList_Lazy_DHP_st_less)\
    CPPUNIT_TEST(SplitList_Lazy_DHP_st_less_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPI_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPI_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPI_st_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPI_dyn_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPI_st_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPI_st_less_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPB_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPB_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPB_st_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPB_dyn_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPB_st_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPB_st_less_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPT_dyn_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPT_dyn_cmp_stat)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPT_st_cmp)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPT_dyn_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPT_st_less)\
    CPPUNIT_TEST(SplitList_Lazy_RCU_GPT_st_less_stat)\
    CDSUNIT_TEST_SplitList_RCU_signal

//********************************************************************
// CuckooSet

#define CDSUNIT_DECLARE_CuckooSet \
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_list_unord)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_list_unord_stat)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_list_ord)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_list_ord_stat)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_vector_unord)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_vector_ord)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_vector_unord_stat)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_vector_ord_stat)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_list_unord)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_list_ord)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_list_unord_stat)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_list_ord_stat)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_vector_unord)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_vector_unord_stat)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_vector_ord) \
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_vector_ord_stat) \
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_list_unord_storehash)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_list_ord_storehash)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_vector_unord_storehash)\
    TEST_CASE(tag_CuckooSet, CuckooStripedSet_vector_ord_storehash)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_list_unord_storehash)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_list_ord_storehash)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_vector_unord_storehash)\
    TEST_CASE(tag_CuckooSet, CuckooRefinableSet_vector_ord_storehash)

#define CDSUNIT_TEST_CuckooSet \
    CPPUNIT_TEST(CuckooStripedSet_list_unord)\
    CPPUNIT_TEST(CuckooStripedSet_list_unord_stat)\
    CPPUNIT_TEST(CuckooStripedSet_list_unord_storehash)\
    CPPUNIT_TEST(CuckooStripedSet_list_ord)\
    CPPUNIT_TEST(CuckooStripedSet_list_ord_stat)\
    CPPUNIT_TEST(CuckooStripedSet_list_ord_storehash)\
    CPPUNIT_TEST(CuckooStripedSet_vector_unord)\
    CPPUNIT_TEST(CuckooStripedSet_vector_unord_stat)\
    CPPUNIT_TEST(CuckooStripedSet_vector_unord_storehash)\
    CPPUNIT_TEST(CuckooStripedSet_vector_ord)\
    CPPUNIT_TEST(CuckooStripedSet_vector_ord_stat)\
    CPPUNIT_TEST(CuckooStripedSet_vector_ord_storehash)\
    CPPUNIT_TEST(CuckooRefinableSet_list_unord)\
    CPPUNIT_TEST(CuckooRefinableSet_list_unord_stat)\
    CPPUNIT_TEST(CuckooRefinableSet_list_unord_storehash)\
    CPPUNIT_TEST(CuckooRefinableSet_list_ord)\
    CPPUNIT_TEST(CuckooRefinableSet_list_ord_stat)\
    CPPUNIT_TEST(CuckooRefinableSet_list_ord_storehash)\
    CPPUNIT_TEST(CuckooRefinableSet_vector_unord)\
    CPPUNIT_TEST(CuckooRefinableSet_vector_unord_stat)\
    CPPUNIT_TEST(CuckooRefinableSet_vector_unord_storehash)\
    CPPUNIT_TEST(CuckooRefinableSet_vector_ord) \
    CPPUNIT_TEST(CuckooRefinableSet_vector_ord_stat) \
    CPPUNIT_TEST(CuckooRefinableSet_vector_ord_storehash)

//********************************************************************
// SkipListSet

#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
#   define CDSUNIT_DECLARE_SkipListSet_RCU_signal \
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_shb_less_pascal)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_shb_cmp_pascal_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_shb_less_xorshift)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_shb_cmp_xorshift_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_sht_less_pascal)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_sht_cmp_pascal_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_sht_less_xorshift)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_sht_cmp_xorshift_stat)

#   define CDSUNIT_TEST_SkipListSet_RCU_signal \
    CPPUNIT_TEST(SkipListSet_rcu_shb_less_pascal)\
    CPPUNIT_TEST(SkipListSet_rcu_shb_cmp_pascal_stat)\
    CPPUNIT_TEST(SkipListSet_rcu_shb_less_xorshift)\
    CPPUNIT_TEST(SkipListSet_rcu_shb_cmp_xorshift_stat)\
    CPPUNIT_TEST(SkipListSet_rcu_sht_less_pascal)\
    CPPUNIT_TEST(SkipListSet_rcu_sht_cmp_pascal_stat)\
    CPPUNIT_TEST(SkipListSet_rcu_sht_less_xorshift)\
    CPPUNIT_TEST(SkipListSet_rcu_sht_cmp_xorshift_stat)

#else
#   define CDSUNIT_DECLARE_SkipListSet_RCU_signal
#   define CDSUNIT_TEST_SkipListSet_RCU_signal
#endif

#define CDSUNIT_DECLARE_SkipListSet \
    TEST_CASE(tag_SkipListSet, SkipListSet_hp_less_pascal)\
    TEST_CASE(tag_SkipListSet, SkipListSet_hp_cmp_pascal_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_hp_less_xorshift)\
    TEST_CASE(tag_SkipListSet, SkipListSet_hp_cmp_xorshift_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_dhp_less_pascal)\
    TEST_CASE(tag_SkipListSet, SkipListSet_dhp_cmp_pascal_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_dhp_less_xorshift)\
    TEST_CASE(tag_SkipListSet, SkipListSet_dhp_cmp_xorshift_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpi_less_pascal)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpi_cmp_pascal_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpi_less_xorshift)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpi_cmp_xorshift_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpb_less_pascal)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpb_cmp_pascal_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpb_less_xorshift)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpb_cmp_xorshift_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpt_less_pascal)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpt_cmp_pascal_stat)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpt_less_xorshift)\
    TEST_CASE(tag_SkipListSet, SkipListSet_rcu_gpt_cmp_xorshift_stat)\
    CDSUNIT_DECLARE_SkipListSet_RCU_signal

#define CDSUNIT_TEST_SkipListSet \
    CPPUNIT_TEST(SkipListSet_hp_less_pascal)\
    CPPUNIT_TEST(SkipListSet_hp_cmp_pascal_stat)\
    CPPUNIT_TEST(SkipListSet_hp_less_xorshift)\
    CPPUNIT_TEST(SkipListSet_hp_cmp_xorshift_stat)\
    CPPUNIT_TEST(SkipListSet_dhp_less_pascal)\
    CPPUNIT_TEST(SkipListSet_dhp_cmp_pascal_stat)\
    CPPUNIT_TEST(SkipListSet_dhp_less_xorshift)\
    CPPUNIT_TEST(SkipListSet_dhp_cmp_xorshift_stat)\
    CPPUNIT_TEST(SkipListSet_rcu_gpi_less_pascal)\
    CPPUNIT_TEST(SkipListSet_rcu_gpi_cmp_pascal_stat)\
    CPPUNIT_TEST(SkipListSet_rcu_gpi_less_xorshift)\
    CPPUNIT_TEST(SkipListSet_rcu_gpi_cmp_xorshift_stat)\
    CPPUNIT_TEST(SkipListSet_rcu_gpb_less_pascal)\
    CPPUNIT_TEST(SkipListSet_rcu_gpb_cmp_pascal_stat)\
    CPPUNIT_TEST(SkipListSet_rcu_gpb_less_xorshift)\
    CPPUNIT_TEST(SkipListSet_rcu_gpb_cmp_xorshift_stat)\
    CPPUNIT_TEST(SkipListSet_rcu_gpt_less_pascal)\
    CPPUNIT_TEST(SkipListSet_rcu_gpt_cmp_pascal_stat)\
    CPPUNIT_TEST(SkipListSet_rcu_gpt_less_xorshift)\
    CPPUNIT_TEST(SkipListSet_rcu_gpt_cmp_xorshift_stat)\
    CDSUNIT_TEST_SkipListSet_RCU_signal

//********************************************************************
// EllenBinTreeSet

#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
#   define CDSUNIT_DECLARE_EllenBinTreeSet_RCU_signal \
        TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_shb)\
        TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_shb_stat)\
        TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_sht)\
        TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_sht_stat)

#   define CDSUNIT_TEST_EllenBinTreeSet_RCU_signal \
        CPPUNIT_TEST(EllenBinTreeSet_rcu_shb)\
        CPPUNIT_TEST(EllenBinTreeSet_rcu_shb_stat)\
        CPPUNIT_TEST(EllenBinTreeSet_rcu_sht)\
        CPPUNIT_TEST(EllenBinTreeSet_rcu_sht_stat)
#else
#   define CDSUNIT_DECLARE_EllenBinTreeSet_RCU_signal
#   define CDSUNIT_TEST_EllenBinTreeSet_RCU_signal
#endif

#define CDSUNIT_DECLARE_EllenBinTreeSet \
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_hp)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_yield_hp)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_hp_stat)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_dhp)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_yield_dhp)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_dhp_stat)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_gpi)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_gpi_stat)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_gpb)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_yield_rcu_gpb)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_gpb_stat)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_gpt)\
    TEST_CASE(tag_EllenBinTreeSet, EllenBinTreeSet_rcu_gpt_stat)\
    CDSUNIT_DECLARE_EllenBinTreeSet_RCU_signal

#define CDSUNIT_TEST_EllenBinTreeSet \
    CPPUNIT_TEST(EllenBinTreeSet_hp)\
    CPPUNIT_TEST(EllenBinTreeSet_yield_hp)\
    CPPUNIT_TEST(EllenBinTreeSet_hp_stat)\
    CPPUNIT_TEST(EllenBinTreeSet_dhp)\
    CPPUNIT_TEST(EllenBinTreeSet_yield_dhp)\
    CPPUNIT_TEST(EllenBinTreeSet_dhp_stat)\
    CPPUNIT_TEST(EllenBinTreeSet_rcu_gpi)\
    /*CPPUNIT_TEST(EllenBinTreeSet_rcu_gpi_stat)*/\
    CPPUNIT_TEST(EllenBinTreeSet_rcu_gpb)\
    CPPUNIT_TEST(EllenBinTreeSet_yield_rcu_gpb)\
    CPPUNIT_TEST(EllenBinTreeSet_rcu_gpb_stat)\
    CPPUNIT_TEST(EllenBinTreeSet_rcu_gpt)\
    CPPUNIT_TEST(EllenBinTreeSet_rcu_gpt_stat)\
    CDSUNIT_TEST_EllenBinTreeSet_RCU_signal

//********************************************************************
// StripedSet

#define CDSUNIT_DECLARE_StripedSet_common \
    TEST_CASE( tag_StripedSet, StripedSet_list) \
    TEST_CASE( tag_StripedSet, StripedSet_vector) \
    TEST_CASE( tag_StripedSet, StripedSet_set) \
    TEST_CASE( tag_StripedSet, StripedSet_hashset) \
    TEST_CASE( tag_StripedSet, StripedSet_boost_unordered_set) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_list) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_vector) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_set) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_hashset) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_boost_unordered_set)

#define CDSUNIT_TEST_StripedSet_common \
    CPPUNIT_TEST(StripedSet_list) \
    CPPUNIT_TEST(StripedSet_vector) \
    CPPUNIT_TEST(StripedSet_set) \
    CPPUNIT_TEST(StripedSet_hashset) \
    CPPUNIT_TEST(StripedSet_boost_unordered_set) \
    CPPUNIT_TEST(StripedSet_rational_list) \
    CPPUNIT_TEST(StripedSet_rational_vector) \
    CPPUNIT_TEST(StripedSet_rational_set) \
    CPPUNIT_TEST(StripedSet_rational_hashset) \
    CPPUNIT_TEST(StripedSet_rational_boost_unordered_set)

#if BOOST_VERSION >= 104800
#   define CDSUNIT_DECLARE_StripedSet_boost_container \
    TEST_CASE( tag_StripedSet, StripedSet_boost_list) \
    TEST_CASE( tag_StripedSet, StripedSet_boost_slist) \
    TEST_CASE( tag_StripedSet, StripedSet_boost_vector) \
    TEST_CASE( tag_StripedSet, StripedSet_boost_stable_vector) \
    TEST_CASE( tag_StripedSet, StripedSet_boost_set) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_boost_list) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_boost_slist) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_boost_vector) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_boost_stable_vector) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_boost_set)

#   define CDSUNIT_TEST_StripedSet_boost_container \
    CPPUNIT_TEST(StripedSet_boost_list) \
    CPPUNIT_TEST(StripedSet_boost_slist) \
    CPPUNIT_TEST(StripedSet_boost_vector) \
    CPPUNIT_TEST(StripedSet_boost_stable_vector) \
    CPPUNIT_TEST(StripedSet_boost_set) \
    CPPUNIT_TEST(StripedSet_rational_boost_list) \
    CPPUNIT_TEST(StripedSet_rational_boost_slist) \
    CPPUNIT_TEST(StripedSet_rational_boost_vector) \
    CPPUNIT_TEST(StripedSet_rational_boost_stable_vector) \
    CPPUNIT_TEST(StripedSet_rational_boost_set)
#else
#   define CDSUNIT_DECLARE_StripedSet_boost_container
#   define CDSUNIT_TEST_StripedSet_boost_container
#endif

#if BOOST_VERSION >= 104800 && defined(CDS_UNIT_SET_TYPES_ENABLE_BOOST_FLAT_CONTAINERS)
#   define CDSUNIT_DECLARE_StripedSet_boost_flat_container \
    TEST_CASE( tag_StripedSet, StripedSet_boost_flat_set) \
    TEST_CASE( tag_StripedSet, StripedSet_rational_boost_flat_set)

#   define CDSUNIT_TEST_StripedSet_boost_flat_container \
    CPPUNIT_TEST(StripedSet_boost_flat_set) \
    CPPUNIT_TEST(StripedSet_rational_boost_flat_set)
#else
#   define CDSUNIT_DECLARE_StripedSet_boost_flat_container
#   define CDSUNIT_TEST_StripedSet_boost_flat_container
#endif

#define CDSUNIT_DECLARE_StripedSet \
    CDSUNIT_DECLARE_StripedSet_common \
    CDSUNIT_DECLARE_StripedSet_boost_container \
    CDSUNIT_DECLARE_StripedSet_boost_flat_container

#define CDSUNIT_TEST_StripedSet \
    CDSUNIT_TEST_StripedSet_common \
    CDSUNIT_TEST_StripedSet_boost_container \
    CDSUNIT_TEST_StripedSet_boost_flat_container


#define CDSUNIT_DECLARE_RefinableSet_common \
    TEST_CASE( tag_StripedSet, RefinableSet_list) \
    TEST_CASE( tag_StripedSet, RefinableSet_vector) \
    TEST_CASE( tag_StripedSet, RefinableSet_set) \
    TEST_CASE( tag_StripedSet, RefinableSet_hashset) \
    TEST_CASE( tag_StripedSet, RefinableSet_boost_unordered_set) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_list) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_vector) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_set) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_hashset) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_boost_unordered_set)


//********************************************************************
// RefinableSet

#define CDSUNIT_TEST_RefinableSet_common \
    CPPUNIT_TEST(RefinableSet_list) \
    CPPUNIT_TEST(RefinableSet_vector) \
    CPPUNIT_TEST(RefinableSet_set) \
    CPPUNIT_TEST(RefinableSet_hashset) \
    CPPUNIT_TEST(RefinableSet_boost_unordered_set) \
    CPPUNIT_TEST(RefinableSet_rational_list) \
    CPPUNIT_TEST(RefinableSet_rational_vector) \
    CPPUNIT_TEST(RefinableSet_rational_set) \
    CPPUNIT_TEST(RefinableSet_rational_hashset) \
    CPPUNIT_TEST(RefinableSet_rational_boost_unordered_set)

#if BOOST_VERSION >= 104800
#   define CDSUNIT_DECLARE_RefinableSet_boost_container \
    TEST_CASE( tag_StripedSet, RefinableSet_boost_list) \
    TEST_CASE( tag_StripedSet, RefinableSet_boost_slist) \
    TEST_CASE( tag_StripedSet, RefinableSet_boost_vector) \
    TEST_CASE( tag_StripedSet, RefinableSet_boost_stable_vector) \
    TEST_CASE( tag_StripedSet, RefinableSet_boost_set) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_boost_list) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_boost_slist) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_boost_vector) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_boost_stable_vector) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_boost_set)

#   define CDSUNIT_TEST_RefinableSet_boost_container \
    CPPUNIT_TEST(RefinableSet_boost_list) \
    CPPUNIT_TEST(RefinableSet_boost_slist) \
    CPPUNIT_TEST(RefinableSet_boost_vector) \
    CPPUNIT_TEST(RefinableSet_boost_stable_vector) \
    CPPUNIT_TEST(RefinableSet_boost_set) \
    CPPUNIT_TEST(RefinableSet_rational_boost_list) \
    CPPUNIT_TEST(RefinableSet_rational_boost_slist) \
    CPPUNIT_TEST(RefinableSet_rational_boost_vector) \
    CPPUNIT_TEST(RefinableSet_rational_boost_stable_vector) \
    CPPUNIT_TEST(RefinableSet_rational_boost_set)
#else
#   define CDSUNIT_DECLARE_RefinableSet_boost_container
#   define CDSUNIT_TEST_RefinableSet_boost_container
#endif

#if BOOST_VERSION >= 104800 && defined(CDS_UNIT_SET_TYPES_ENABLE_BOOST_FLAT_CONTAINERS)
#   define CDSUNIT_DECLARE_RefinableSet_boost_flat_container \
    TEST_CASE( tag_StripedSet, RefinableSet_boost_flat_set) \
    TEST_CASE( tag_StripedSet, RefinableSet_rational_boost_flat_set)

#   define CDSUNIT_TEST_RefinableSet_boost_flat_container \
    CPPUNIT_TEST(RefinableSet_boost_flat_set) \
    CPPUNIT_TEST(RefinableSet_rational_boost_flat_set)
#else
#   define CDSUNIT_DECLARE_RefinableSet_boost_flat_container
#   define CDSUNIT_TEST_RefinableSet_boost_flat_container
#endif

#define CDSUNIT_DECLARE_RefinableSet \
    CDSUNIT_DECLARE_RefinableSet_common \
    CDSUNIT_DECLARE_RefinableSet_boost_container \
    CDSUNIT_DECLARE_RefinableSet_boost_flat_container

#define CDSUNIT_TEST_RefinableSet \
    CDSUNIT_TEST_RefinableSet_common \
    CDSUNIT_TEST_RefinableSet_boost_container \
    CDSUNIT_TEST_RefinableSet_boost_flat_container


//***********************************************
// FeldmanHashSet

// For fixed-sized key - no hash function is needed

#undef CDSUNIT_DECLARE_FeldmanHashSet_fixed
#undef CDSUNIT_DECLARE_FeldmanHashSet_fixed_RCU_signal
#undef CDSUNIT_TEST_FeldmanHashSet_fixed
#undef CDSUNIT_TEST_FeldmanHashSet_fixed_RCU_signal

#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
#   define CDSUNIT_DECLARE_FeldmanHashSet_fixed_RCU_signal  \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_fixed) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_fixed_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_fixed) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_fixed_stat) \

#   define CDSUNIT_TEST_FeldmanHashSet_fixed_RCU_signal \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_fixed) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_fixed_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_fixed) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_fixed_stat) \

#else
#   define CDSUNIT_DECLARE_FeldmanHashSet_fixed_RCU_signal
#   define CDSUNIT_TEST_FeldmanHashSet_fixed_RCU_signal
#endif

#define CDSUNIT_DECLARE_FeldmanHashSet_fixed  \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_hp_fixed) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_hp_fixed_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_dhp_fixed) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_dhp_fixed_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpi_fixed) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpi_fixed_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpb_fixed) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpb_fixed_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpt_fixed) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpt_fixed_stat) \
    CDSUNIT_DECLARE_FeldmanHashSet_fixed_RCU_signal

#define CDSUNIT_TEST_FeldmanHashSet_fixed  \
    CPPUNIT_TEST(FeldmanHashSet_hp_fixed) \
    CPPUNIT_TEST(FeldmanHashSet_hp_fixed_stat) \
    CPPUNIT_TEST(FeldmanHashSet_dhp_fixed) \
    CPPUNIT_TEST(FeldmanHashSet_dhp_fixed_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpi_fixed) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpi_fixed_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpb_fixed) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpb_fixed_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpt_fixed) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpt_fixed_stat) \
    CDSUNIT_TEST_FeldmanHashSet_fixed_RCU_signal

// std::hash
#undef CDSUNIT_DECLARE_FeldmanHashSet_stdhash
#undef CDSUNIT_DECLARE_FeldmanHashSet_stdhash_RCU_signal
#undef CDSUNIT_TEST_FeldmanHashSet_stdhash
#undef CDSUNIT_TEST_FeldmanHashSet_stdhash_RCU_signal

#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
#   define CDSUNIT_DECLARE_FeldmanHashSet_stdhash_RCU_signal  \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_stdhash) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_stdhash_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_stdhash) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_stdhash_stat) \

#   define CDSUNIT_TEST_FeldmanHashSet_stdhash_RCU_signal \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_stdhash) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_stdhash_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_stdhash) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_stdhash_stat) \

#else
#   define CDSUNIT_DECLARE_FeldmanHashSet_stdhash_RCU_signal
#   define CDSUNIT_TEST_FeldmanHashSet_stdhash_RCU_signal
#endif

#define CDSUNIT_DECLARE_FeldmanHashSet_stdhash  \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_hp_stdhash) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_hp_stdhash_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_dhp_stdhash) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_dhp_stdhash_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpi_stdhash) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpi_stdhash_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpb_stdhash) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpb_stdhash_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpt_stdhash) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpt_stdhash_stat) \
    CDSUNIT_DECLARE_FeldmanHashSet_stdhash_RCU_signal

#define CDSUNIT_TEST_FeldmanHashSet_stdhash  \
    CPPUNIT_TEST(FeldmanHashSet_hp_stdhash) \
    CPPUNIT_TEST(FeldmanHashSet_hp_stdhash_stat) \
    CPPUNIT_TEST(FeldmanHashSet_dhp_stdhash) \
    CPPUNIT_TEST(FeldmanHashSet_dhp_stdhash_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpi_stdhash) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpi_stdhash_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpb_stdhash) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpb_stdhash_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpt_stdhash) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpt_stdhash_stat) \
    CDSUNIT_TEST_FeldmanHashSet_stdhash_RCU_signal


// CityHash -only for 64bit

#undef CDSUNIT_DECLARE_FeldmanHashSet_city
#undef CDSUNIT_DECLARE_FeldmanHashSet_city_RCU_signal
#undef CDSUNIT_TEST_FeldmanHashSet_city
#undef CDSUNIT_TEST_FeldmanHashSet_city_RCU_signal

#if CDS_BUILD_BITS == 64

#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
#   define CDSUNIT_DECLARE_FeldmanHashSet_city_RCU_signal  \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_city64) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_city64_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_city64) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_city64_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_city128) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_city128_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_city128) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_city128_stat) \

#   define CDSUNIT_TEST_FeldmanHashSet_city_RCU_signal \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_city64) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_city64_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_city64) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_city64_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_city128) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_shb_city128_stat) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_city128) \
        TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_sht_city128_stat) \

#else
#   define CDSUNIT_DECLARE_FeldmanHashSet_city_RCU_signal
#   define CDSUNIT_TEST_FeldmanHashSet_city_RCU_signal
#endif

#define CDSUNIT_DECLARE_FeldmanHashSet_city  \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_hp_city64) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_hp_city64_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_dhp_city64) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_dhp_city64_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpi_city64) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpi_city64_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpb_city64) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpb_city64_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpt_city64) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpt_city64_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_hp_city128) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_hp_city128_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_dhp_city128) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_dhp_city128_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpi_city128) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpi_city128_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpb_city128) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpb_city128_stat) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpt_city128) \
    TEST_CASE(tag_FeldmanHashSet, FeldmanHashSet_rcu_gpt_city128_stat) \
    CDSUNIT_DECLARE_FeldmanHashSet_city_RCU_signal

#define CDSUNIT_TEST_FeldmanHashSet_city  \
    CPPUNIT_TEST(FeldmanHashSet_hp_city64) \
    CPPUNIT_TEST(FeldmanHashSet_hp_city64_stat) \
    CPPUNIT_TEST(FeldmanHashSet_dhp_city64) \
    CPPUNIT_TEST(FeldmanHashSet_dhp_city64_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpi_city64) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpi_city64_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpb_city64) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpb_city64_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpt_city64) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpt_city64_stat) \
    CPPUNIT_TEST(FeldmanHashSet_hp_city128) \
    CPPUNIT_TEST(FeldmanHashSet_hp_city128_stat) \
    CPPUNIT_TEST(FeldmanHashSet_dhp_city128) \
    CPPUNIT_TEST(FeldmanHashSet_dhp_city128_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpi_city128) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpi_city128_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpb_city128) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpb_city128_stat) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpt_city128) \
    CPPUNIT_TEST(FeldmanHashSet_rcu_gpt_city128_stat) \
    CDSUNIT_TEST_FeldmanHashSet_city_RCU_signal

#else
#   define CDSUNIT_DECLARE_FeldmanHashSet_city
#   define CDSUNIT_DECLARE_FeldmanHashSet_city_RCU_signal
#   define CDSUNIT_TEST_FeldmanHashSet_city
#   define CDSUNIT_TEST_FeldmanHashSet_city_RCU_signal
#endif // CDS_BUILD_BITS == 64


// All

#define CDSUNIT_DECLARE_FeldmanHashSet \
    CDSUNIT_DECLARE_FeldmanHashSet_fixed \
    CDSUNIT_DECLARE_FeldmanHashSet_stdhash \
    CDSUNIT_DECLARE_FeldmanHashSet_city

#define CDSUNIT_TEST_FeldmanHashSet \
    CDSUNIT_TEST_FeldmanHashSet_fixed \
    CDSUNIT_TEST_FeldmanHashSet_stdhash \
    CDSUNIT_TEST_FeldmanHashSet_city
