
#include <UnitTest.h>

UNITTEST_TESTSET_DECLARATION copy_set;
UNITTEST_TESTSET_DECLARATION concat_set;
UNITTEST_TESTSET_DECLARATION replace_set;
UNITTEST_TESTSET_DECLARATION format_set;
UNITTEST_TESTSET_DECLARATION decimal_set;
UNITTEST_TESTSET_DECLARATION float_set;

UNITTEST_TESTSET_FIXTURES (utTestSets)
{
    new_TestSet(copy_set),
    new_TestSet(concat_set),
    new_TestSet(replace_set),
    new_TestSet(format_set),
    new_TestSet(decimal_set),
    new_TestSet(float_set)
};

UNTITTEST_TESTSET_HANDLER();
