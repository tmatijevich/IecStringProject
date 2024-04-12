#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

_TEST test_last_variable(void)
{
    char find = '3';
    char a[] = "abcde12345";

    /* Call the function with variable arguments */
    uint32_t address = IecStringLast(a, find);

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abcde12345", a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 7, address);

    TEST_DONE;
}

_TEST test_last_literal(void)
{
    char a[] = "abcde12345";

    /* Call the function with literal character */
    uint32_t address = IecStringLast(a, '3');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abcde12345", a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 7, address);

    TEST_DONE;
}

_TEST test_last_first(void)
{
    char a[] = "abcde12345";

    uint32_t address = IecStringLast(a, 'a');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abcde12345", a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a , address);

    TEST_DONE;
}

_TEST test_last_last(void)
{
    char a[] = "abcde12345";

    uint32_t address = IecStringLast(a, '5');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abcde12345", a);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 9, address);

    TEST_DONE;
}

_TEST test_last_multiple(void)
{
    char b[] = "abc123abc123";

    uint32_t address = IecStringLast(b, 'b');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abc123abc123", b);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)b + 7, address);

    TEST_DONE;
}

_TEST test_last_many(void)
{
    char c[] = "aaaaa aaaaa";

    uint32_t address = IecStringLast(c, 'a');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("aaaaa aaaaa", c);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)c + 10, address);

    TEST_DONE;
}

_TEST test_last_none(void)
{
    char b[] = "abc123abc123";

    uint32_t address = IecStringLast(b, 'g');

    /* Test the input string has not be modified */
    TEST_ASSERT_EQUAL_STRING("abc123abc123", b);
    /* Test the result */
    TEST_ASSERT_EQUAL_INT(0, address);

    TEST_DONE;
}

_TEST test_last_special(void)
{
    char find = 6;
    char a[] = "abcde12345";
    memset(a + 3, find, 1);

    /* Call with special character */
    uint32_t address = IecStringLast(a, find);

    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 3, address);

    TEST_DONE;
}

_TEST test_last_nonascii(void)
{
    char find = 140;
    char a[] = "abcde12345";
    memset(a + 3, find, 1);

    /* Call with non-ascii character */
    uint32_t address = IecStringLast(a, find);

    /* Test the result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 3, address);

    TEST_DONE;
}

_TEST test_last_empty(void)
{
    char a[] = "";

    /* Call with empty string */
    uint32_t address = IecStringLast(a, '3');

    /* Test the result */
    TEST_ASSERT_EQUAL_INT(0, address);

    TEST_DONE;
}

_TEST test_last_null(void)
{
    /* Call with null string */
    uint32_t address = IecStringLast(NULL, '3');

    /* Test the result */
    TEST_ASSERT_EQUAL_INT(0, address);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringLast from variable", test_last_variable),
    new_TestFixture("IecStringLast from literal", test_last_literal),
    new_TestFixture("IecStringLast first character", test_last_first),
    new_TestFixture("IecStringLast last character", test_last_last),
    new_TestFixture("IecStringLast multiple characters", test_last_multiple),
    new_TestFixture("IecStringLast many characters", test_last_many),
    new_TestFixture("IecStringLast zero characters", test_last_none),
    new_TestFixture("IecStringLast special character", test_last_special),
    new_TestFixture("IecStringLast non-ascii character", test_last_nonascii),
    new_TestFixture("IecStringLast empty string", test_last_empty),
    new_TestFixture("IecStringLast null string", test_last_null)
};

UNITTEST_CALLER_TEST(last_set, "IecStringLast test set", fixtures);
