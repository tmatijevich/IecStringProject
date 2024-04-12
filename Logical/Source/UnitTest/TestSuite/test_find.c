#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

#define STRING_SAMPLE "The quick brown fox jumped over the lazy dog"
#define SAMPLE_SEARCH "Red left his red house wearing \
a red shirt driving a red car"

_TEST test_find_variable(void)
{
    char a[] = STRING_SAMPLE;
    char find[] = "fox";

    /* Call the function with variable arguments */
    uint32_t address = IecStringFind(a, find);

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING(STRING_SAMPLE, a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 16, address);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFind from variable", test_find_variable)
};

UNITTEST_CALLER_TEST(find_set, "IecStringFind test set", fixtures);
