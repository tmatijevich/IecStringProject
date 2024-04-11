#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

_TEST test_first_variable(void)
{
    char find = '3';
    char a[] = "abcde12345";

    /* Call the function with variable arguments */
    uint32_t address = IecStringFirst(a, find);

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abcde12345", a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 7, address);

    TEST_DONE;
}

_TEST test_first_literal(void)
{
    char a[] = "abcde12345";

    /* Call the function with literal character */
    uint32_t address = IecStringFirst(a, '3');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abcde12345", a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 7, address);

    TEST_DONE;
}

_TEST test_first_first(void)
{
    char a[] = "abcde12345";

    uint32_t address = IecStringFirst(a, 'a');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abcde12345", a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a , address);

    TEST_DONE;
}

_TEST test_first_last(void)
{
    char a[] = "abcde12345";

    uint32_t address = IecStringFirst(a, '5');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abcde12345", a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 9, address);

    TEST_DONE;
}

_TEST test_first_multiple(void)
{
    char b[] = "abc123abc123";

    uint32_t address = IecStringFirst(b, 'b');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abc123abc123", b);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)b + 1, address);

    TEST_DONE;
}

_TEST test_first_none(void)
{
    char b[] = "abc123abc123";

    uint32_t address = IecStringFirst(b, 'g');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abc123abc123", b);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT(0, address);

    TEST_DONE;
}

_TEST test_first_special(void)
{
    char find = 6;
    char a[] = "abcde12345";
    memset(a + 3, find, 1);

    /* Call with special character */
    uint32_t address = IecStringFirst(a, find);

    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 3, address);

    TEST_DONE;
}

_TEST test_first_nonascii(void)
{
    char find = 140;
    char a[] = "abcde12345";
    memset(a + 3, find, 1);

    /* Call with non-ascii character */
    uint32_t address = IecStringFirst(a, find);

    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 3, address);

    TEST_DONE;
}

_TEST test_first_empty(void)
{
    char a[] = "";

    /* Call with empty string */
    uint32_t address = IecStringFirst(a, '3');

    /* Test the result */
    TEST_ASSERT_EQUAL_INT(0, address);

    TEST_DONE;
}

_TEST test_first_null(void)
{
    /* Call with null string */
    uint32_t address = IecStringFirst(NULL, '3');

    /* Test the result */
    TEST_ASSERT_EQUAL_INT(0, address);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFirst from variable", test_first_variable),
    new_TestFixture("IecStringFirst from literal", test_first_literal),
    new_TestFixture("IecStringFirst first character", test_first_first),
    new_TestFixture("IecStringFirst last character", test_first_last),
    new_TestFixture("IecStringFirst multiple characters", test_first_multiple),
    new_TestFixture("IecStringFirst zero characters", test_first_none),
    new_TestFixture("IecStringFirst special character", test_first_special),
    new_TestFixture("IecStringFirst non-ascii character", test_first_nonascii),
    new_TestFixture("IecStringFirst empty string", test_first_empty),
    new_TestFixture("IecStringFirst null string", test_first_null)
};

UNITTEST_CALLER_TEST(first_set, "IecStringFirst test set", fixtures);
