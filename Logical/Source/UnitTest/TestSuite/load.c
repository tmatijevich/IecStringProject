
#include <UnitTest.h>

UNITTEST_TESTSET_DECLARATION copy_set;
UNITTEST_TESTSET_DECLARATION concat_set;
UNITTEST_TESTSET_DECLARATION compare_set;
UNITTEST_TESTSET_DECLARATION length_set;
UNITTEST_TESTSET_DECLARATION first_set;
UNITTEST_TESTSET_DECLARATION last_set;
UNITTEST_TESTSET_DECLARATION find_set;
UNITTEST_TESTSET_DECLARATION first_in_set;
UNITTEST_TESTSET_DECLARATION length_in_set;
UNITTEST_TESTSET_DECLARATION start_set;
UNITTEST_TESTSET_DECLARATION end_set;
UNITTEST_TESTSET_DECLARATION replace_set;
UNITTEST_TESTSET_DECLARATION split_set;
UNITTEST_TESTSET_DECLARATION format_set;
UNITTEST_TESTSET_DECLARATION decimal_set;
UNITTEST_TESTSET_DECLARATION float_set;
UNITTEST_TESTSET_DECLARATION date_time_set;

UNITTEST_TESTSET_FIXTURES (utTestSets)
{
    new_TestSet(copy_set),
    new_TestSet(concat_set),
    new_TestSet(compare_set),
    new_TestSet(length_set),
    new_TestSet(first_set),
    new_TestSet(last_set),
    new_TestSet(find_set),
    new_TestSet(first_in_set),
    new_TestSet(length_in_set),
    new_TestSet(start_set),
    new_TestSet(end_set),
    new_TestSet(replace_set),
    new_TestSet(split_set),
    new_TestSet(format_set),
    new_TestSet(decimal_set),
    new_TestSet(float_set),
    new_TestSet(date_time_set)
};

UNTITTEST_TESTSET_HANDLER();
