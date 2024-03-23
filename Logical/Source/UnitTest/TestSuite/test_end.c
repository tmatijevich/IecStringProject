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

UNITTEST_FIXTURES(fixtures)
{
    new_TestFixture("IecStringEndsWith from variables", test_end_variable)
};

UNITTEST_CALLER_TEST (end_set, "IecStringEndsWith test set", fixtures);
