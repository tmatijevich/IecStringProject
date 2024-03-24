#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_STRING 11
#define STRING_SAMPLE_GREATER "ABC123"
#define STRING_SAMPLE_EQUAL "ABC"
#define STRING_SAMPLE_LESSER "AB"
#define STRING_MATCH "ABC"
#define STRING_NO_MATCH "DEF"

_TEST test_start_variable(void)
{
    char a[SIZE_STRING], b[SIZE_STRING];
    strcpy(a, STRING_SAMPLE_GREATER);
    strcpy(b, STRING_MATCH);

    uint8_t result = IecStringStartsWith(a, b);

    /* No modifications to strings */
    TEST_ASSERT_EQUAL_STRING(STRING_SAMPLE_GREATER, a);
    TEST_ASSERT_EQUAL_STRING(STRING_MATCH, b);
    /* Match */
    TEST_ASSERT_EQUAL_INT(true, result);

    TEST_DONE;
}

_TEST test_start_literal(void)
{
    uint8_t result = IecStringStartsWith(STRING_SAMPLE_GREATER, STRING_MATCH);

    TEST_ASSERT_EQUAL_INT(true, result);

    TEST_DONE;
}

_TEST test_start_equal_match(void)
{
    uint8_t result = IecStringStartsWith(STRING_SAMPLE_EQUAL, STRING_MATCH);

    TEST_ASSERT_EQUAL_INT(true, result);

    TEST_DONE;
}

_TEST test_start_greater_no_match(void)
{
    uint8_t result = IecStringStartsWith(STRING_SAMPLE_GREATER, STRING_NO_MATCH);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

_TEST test_start_equal_no_match(void)
{
    uint8_t result = IecStringStartsWith(STRING_SAMPLE_EQUAL, STRING_NO_MATCH);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

_TEST test_start_lesser(void)
{
    uint8_t result = IecStringStartsWith(STRING_SAMPLE_LESSER, STRING_MATCH);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

_TEST test_start_null_1(void)
{
    uint8_t result = IecStringStartsWith(NULL, STRING_MATCH);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

_TEST test_start_null_2(void)
{
    uint8_t result = IecStringStartsWith(STRING_SAMPLE_GREATER, NULL);

    TEST_ASSERT_EQUAL_INT(false, result);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures)
{
    new_TestFixture("IecStringStartsWith from variables", test_start_variable),
    new_TestFixture("IecStringStartsWith from literals", test_start_literal),
    new_TestFixture("IecStringStartsWith equal size match", test_start_equal_match),
    new_TestFixture("IecStringStartsWith greater size no match", test_start_greater_no_match),
    new_TestFixture("IecStringStartsWith equal size no match", test_start_equal_no_match),
    new_TestFixture("IecStringStartsWith lesser size", test_start_lesser),
    new_TestFixture("IecStringStartsWith null string 1", test_start_null_1),
    new_TestFixture("IecStringStartsWith null string 2", test_start_null_2)
};

UNITTEST_CALLER_TEST (start_set, "IecStringStartsWith test set", fixtures);
