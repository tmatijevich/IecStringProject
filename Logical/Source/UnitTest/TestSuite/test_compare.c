#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_STRING 11
#define STRING_SAMPLE "ABC123"
#define STRING_MATCH "ABC"
#define STRING_NO_MATCH "DEF"

_TEST test_compare_variable(void)
{
    char a[SIZE_STRING], b[SIZE_STRING];
    strcpy(a, STRING_SAMPLE);
    strcpy(b, STRING_MATCH);

    int16_t result = IecStringCompare(a, b, 3);

    /* No modifications to strings */
    TEST_ASSERT_EQUAL_STRING(STRING_SAMPLE, a);
    TEST_ASSERT_EQUAL_STRING(STRING_MATCH, b);
    /* Equal */
    TEST_ASSERT_EQUAL_INT(true, result == 0);

    TEST_DONE;
}

_TEST test_compare_literal(void)
{
    int16_t result = IecStringCompare(STRING_SAMPLE, STRING_MATCH, 4);

    /* Greater than */
    TEST_ASSERT_EQUAL_INT(true, result > 0);

    TEST_DONE;
}

_TEST test_compare_greater(void)
{
    int16_t result = IecStringCompare(STRING_SAMPLE, STRING_MATCH, sizeof(STRING_SAMPLE));

    /* Greater than */
    TEST_ASSERT_EQUAL_INT(true, result > 0);

    TEST_DONE;
}

_TEST test_compare_lesser(void)
{
    int16_t result = IecStringCompare(STRING_SAMPLE, STRING_NO_MATCH, sizeof(STRING_SAMPLE));

    /* Less than */
    TEST_ASSERT_EQUAL_INT(true, result < 0);

    TEST_DONE;
}

_TEST test_compare_equal(void)
{
    int16_t result = IecStringCompare(STRING_MATCH, STRING_MATCH, 3);

    /* Equal */
    TEST_ASSERT_EQUAL_INT(true, result == 0);

    TEST_DONE;
}

_TEST test_compare_extra(void)
{
    int16_t result = IecStringCompare(STRING_MATCH, STRING_MATCH, 4);

    /* Equal */
    TEST_ASSERT_EQUAL_INT(true, result == 0);

    TEST_DONE;
}

_TEST test_compare_zero(void)
{
    int16_t result = IecStringCompare(STRING_SAMPLE, STRING_NO_MATCH, 0);

    /* Equal */
    TEST_ASSERT_EQUAL_INT(true, result == 0);

    TEST_DONE;
}

_TEST test_compare_null_1(void)
{
    int16_t result = IecStringCompare(NULL, STRING_MATCH, 3);

    /* Greater than */
    TEST_ASSERT_EQUAL_INT(true, result < 0);

    TEST_DONE;
}

_TEST test_compare_null_2(void)
{
    int16_t result = IecStringCompare(STRING_SAMPLE, NULL, 3);

    /* Greater than */
    TEST_ASSERT_EQUAL_INT(true, result > 0);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures)
{
    new_TestFixture("IecStringCompare from variables", test_compare_variable),
    new_TestFixture("IecStringCompare from literals", test_compare_literal),
    new_TestFixture("IecStringCompare greater than", test_compare_greater),
    new_TestFixture("IecStringCompare less than", test_compare_lesser),
    new_TestFixture("IecStringCompare equal", test_compare_equal),
    new_TestFixture("IecStringCompare extra characters", test_compare_extra),
    new_TestFixture("IecStringCompare zero characters", test_compare_zero),
    new_TestFixture("IecStringCompare null string 1", test_compare_null_1),
    new_TestFixture("IecStringCompare null string 2", test_compare_null_2)
};

UNITTEST_CALLER_TEST (compare_set, "IecStringCompare test set", fixtures);
