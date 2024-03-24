#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define STRING_SAMPLE "The quick brown fox jumps over the lazy dog"

_TEST test_length_variable(void)
{
    char a[81];
    strcpy(a, STRING_SAMPLE);

    uint32_t length = IecStringLength(a);

    /* No modifications to strings */
    TEST_ASSERT_EQUAL_STRING(STRING_SAMPLE, a);

    TEST_ASSERT_EQUAL_INT(43, length);

    TEST_DONE;
}

_TEST test_length_literal(void)
{
    uint32_t length = IecStringLength(STRING_SAMPLE);

    TEST_ASSERT_EQUAL_INT(43, length);

    TEST_DONE;
}

_TEST test_length_large(void)
{
    char a[10000] = {0};
    memset(a, 'a', 7500);

    uint32_t length = IecStringLength(a);

    TEST_ASSERT_EQUAL_INT(7500, length);

    TEST_DONE;
}

_TEST test_length_null(void)
{
    uint32_t length = IecStringLength(NULL);

    TEST_ASSERT_EQUAL_INT(0, length);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures)
{
    new_TestFixture("IecStringLength from variables", test_length_variable),
    new_TestFixture("IecStringLength from literals", test_length_literal),
    new_TestFixture("IecStringLength large legth", test_length_large),
    new_TestFixture("IecStringLength null", test_length_null)
};

UNITTEST_CALLER_TEST (length_set, "IecStringLength test set", fixtures);
