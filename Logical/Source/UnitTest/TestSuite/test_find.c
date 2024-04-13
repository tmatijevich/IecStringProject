#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

#define STRING_SAMPLE "The quick brown fox jumps over the lazy dog"

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

_TEST test_find_literal(void)
{
    char a[] = STRING_SAMPLE;

    /* Call the function with variable arguments */
    uint32_t address = IecStringFind(a, "fox");

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING(STRING_SAMPLE, a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 16, address);

    TEST_DONE;
}

_TEST test_find_single(void)
{
    char a[] = STRING_SAMPLE;

    /* Call the function with variable arguments */
    uint32_t address = IecStringFind(a, "k");

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING(STRING_SAMPLE, a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 8, address);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFind from variable", test_find_variable),
    new_TestFixture("IecStringFind from literal", test_find_literal),
    new_TestFixture("IecStringFind single character", test_find_single)
};

UNITTEST_CALLER_TEST(find_set, "IecStringFind test set", fixtures);
