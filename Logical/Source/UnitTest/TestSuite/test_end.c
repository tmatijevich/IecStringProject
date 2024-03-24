#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_STRING 11
#define STRING_SAMPLE_GREATER "ABC123"
#define STRING_SAMPLE_EQUAL "123"
#define STRING_SAMPLE_LESSER "23"
#define STRING_MATCH "123"
#define STRING_NO_MATCH "456"

_TEST test_end_variable(void)
{
    char a[SIZE_STRING], b[SIZE_STRING];
    strcpy(a, STRING_SAMPLE_GREATER);
    strcpy(b, STRING_MATCH);

    uint8_t result = IecStringEndsWith(a, b);

    /* No modifications to strings */
    TEST_ASSERT_EQUAL_STRING(STRING_SAMPLE_GREATER, a);
    TEST_ASSERT_EQUAL_STRING(STRING_MATCH, b);
    /* Match */
    TEST_ASSERT_EQUAL_INT(true, result);

    TEST_DONE;
}

_TEST test_end_literal(void)
{
    uint8_t result = IecStringEndsWith(STRING_SAMPLE_GREATER, STRING_MATCH);

    TEST_ASSERT_EQUAL_INT(true, result);

    TEST_DONE;
}

_TEST test_end_equal_match(void)
{
    uint8_t result = IecStringEndsWith(STRING_SAMPLE_EQUAL, STRING_MATCH);

    TEST_ASSERT_EQUAL_INT(true, result);

    TEST_DONE;
}

_TEST test_end_greater_no_match(void)
{
    uint8_t result = IecStringEndsWith(STRING_SAMPLE_GREATER, STRING_NO_MATCH);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

_TEST test_end_equal_no_match(void)
{
    uint8_t result = IecStringEndsWith(STRING_SAMPLE_EQUAL, STRING_NO_MATCH);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

_TEST test_end_lesser(void)
{
    uint8_t result = IecStringEndsWith(STRING_SAMPLE_LESSER, STRING_MATCH);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

_TEST test_end_null_1(void)
{
    uint8_t result = IecStringEndsWith(NULL, STRING_MATCH);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

_TEST test_end_null_2(void)
{
    uint8_t result = IecStringEndsWith(STRING_SAMPLE_GREATER, NULL);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures)
{
    new_TestFixture("IecStringEndsWith from variables", test_end_variable),
    new_TestFixture("IecStringEndsWith from literals", test_end_literal),
    new_TestFixture("IecStringEndsWith equal size match", test_end_equal_match),
    new_TestFixture("IecStringEndsWith greater size no match", test_end_greater_no_match),
    new_TestFixture("IecStringEndsWith equal size no match", test_end_equal_no_match),
    new_TestFixture("IecStringEndsWith lesser size", test_end_lesser),
    new_TestFixture("IecStringEndsWith null string 1", test_end_null_1),
    new_TestFixture("IecStringEndsWith null string 2", test_end_null_2)
};

UNITTEST_CALLER_TEST (end_set, "IecStringEndsWith test set", fixtures);
