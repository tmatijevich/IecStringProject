
#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST test_integer_zeros(void) {
    char a[81];
    int32_t number, status;

    number = 1234;

    status = IecStringInteger(a, sizeof(a), number, 6, '0');

    TEST_ASSERT_EQUAL_STRING("001234", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_integer_spaces(void) {
    char a[81];
    int32_t number, status;

    number = -5678;

    status = IecStringInteger(a, sizeof(a), number, 6, ' ');

    /* Width includes sign */
    TEST_ASSERT_EQUAL_STRING("- 5678", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    /* Defaults to spaces */
    status = IecStringInteger(a, sizeof(a), number, 6, 0);

    TEST_ASSERT_EQUAL_STRING("- 5678", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_integer_tilde(void) {
    char a[81];
    int32_t number, status;

    number = 9012;

    status = IecStringInteger(a, sizeof(a), number, 6, '~');

    TEST_ASSERT_EQUAL_STRING("~~9012", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_integer_max(void) {
    char a[81];
    int32_t number, status;

    number = INT32_MAX;

    status = IecStringInteger(a, sizeof(a), number, 0, '0');

    TEST_ASSERT_EQUAL_STRING("2147483647", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_integer_min(void) {
    char a[81];
    int32_t number, status;

    number = INT32_MIN;

    status = IecStringInteger(a, sizeof(a), number, 0, '0');

    TEST_ASSERT_EQUAL_STRING("-2147483648", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_integer_size(void) {
    char a[6];
    int32_t number, status;

    strcpy(a, "abc");
    number = 123456;

    status = IecStringInteger(a, sizeof(a), number, 0, '0');

    TEST_ASSERT_EQUAL_STRING("abc", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE, status);

    TEST_DONE;
}

_TEST test_integer_null(void) {
    int32_t number, status;

    number = 123456;

    status = IecStringInteger(NULL, 7, number, 0, '0');

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringInteger zeros", test_integer_zeros),
    new_TestFixture("IecStringInteger spaces", test_integer_spaces),
    new_TestFixture("IecStringInteger tilde", test_integer_tilde),
    new_TestFixture("IecStringInteger max", test_integer_max),
    new_TestFixture("IecStringInteger min", test_integer_min),
    new_TestFixture("IecStringInteger size error", test_integer_size),
    new_TestFixture("IecStringInteger null error", test_integer_null)
};

UNITTEST_CALLER_TEST (padint_set, "IecStringInteger test set", fixtures);
