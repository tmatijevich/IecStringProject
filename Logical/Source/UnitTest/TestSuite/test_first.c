#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

#define SIZE_STRING 81
#define SAMPLE_STRING "abcde12345"
#define SAMPLE_MULTIPLE "abc123abc123"

_TEST test_first_variable(void)
{
    char find = '3';
    char a[SIZE_STRING] = SAMPLE_STRING;

    /* Call the function with variable arguments */
    uint32_t address = IecStringFirst(a, (uint8_t)find);

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING(a, SAMPLE_STRING);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT(&a + 8, address);

    TEST_DONE;
}

_TEST test_first_literal(void)
{
    /* Call the function with literal arguments */
    uint32_t address = IecStringFirst(SAMPLE_STRING, (uint8_t)'3');

    /* Test the result */
    TEST_ASSERT_EQUAL_INT(&SAMPLE_STRING + 8, address);

    TEST_DONE;
}

_TEST test_first_first(void)
{
    uint32_t address = IecStringFirst(SAMPLE_STRING, (uint8_t)'a');

    TEST_ASSERT_EQUAL_INT(&SAMPLE_STRING, address);

    TEST_DONE;
}

_TEST test_first_last(void)
{
    uint32_t address = IecStringFirst(SAMPLE_STRING, (uint8_t)'5');

    TEST_ASSERT_EQUAL_INT(&SAMPLE_STRING + strlen(SAMPLE_STRING), address);

    TEST_DONE;
}

_TEST test_first_multiple(void)
{
    uint32_t address = IecStringFirst(SAMPLE_MULTIPLE, (uint8_t)'b');

    TEST_ASSERT_EQUAL_INT(&SAMPLE_MULTIPLE + 1, address);

    TEST_DONE;
}

_TEST test_first_none(void)
{
    uint32_t address = IecStringFirst(SAMPLE_MULTIPLE, (uint8_t)'g');

    TEST_ASSERT_EQUAL_INT(0, address);

    TEST_DONE;
}

/* Test special character */
/* Test non-ascii character */
/* Test null string */

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFirst from variable", test_first_variable),
    new_TestFixture("IecStringFirst from literal", test_first_literal),
    new_TestFixture("IecStringFirst first character", test_first_first),
    new_TestFixture("IecStringFirst last character", test_first_last),
    new_TestFixture("IecStringFirst multiple characters", test_first_multiple),
    new_TestFixture("IecStringFirst zero characters", test_first_none)
};

UNITTEST_CALLER_TEST(first_set, "IecStringFirst test set", fixtures);
