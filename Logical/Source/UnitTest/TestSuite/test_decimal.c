
#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST test_decimal_zeros(void) {
    char a[81];
    int32_t number, status;

    number = 1234;

    status = IecStringDecimal(a, sizeof(a), number, 6, '0', 0);

    TEST_ASSERT_EQUAL_STRING("001234", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_decimal_spaces(void) {
    char a[81];
    int32_t number, status;

    number = -5678;

    status = IecStringDecimal(a, sizeof(a), number, 6, ' ', 0);

    /* Width includes sign */
    TEST_ASSERT_EQUAL_STRING("- 5678", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    /* Defaults to spaces */
    status = IecStringDecimal(a, sizeof(a), number, 6, 0, 0);

    TEST_ASSERT_EQUAL_STRING("- 5678", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_decimal_sign_pos(void) {
    char a[81];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), 123456, 8, '0', 100);

    TEST_ASSERT_EQUAL_STRING("+0123456", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_decimal_tilde(void) {
    char a[81];
    int32_t number, status;

    number = 9012;

    status = IecStringDecimal(a, sizeof(a), number, 6, '~', 0);

    TEST_ASSERT_EQUAL_STRING("~~9012", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_decimal_max(void) {
    char a[81];
    int32_t number, status;

    number = INT32_MAX;

    status = IecStringDecimal(a, sizeof(a), number, 0, '0', 0);

    TEST_ASSERT_EQUAL_STRING("2147483647", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_decimal_min(void) {
    char a[81];
    int32_t number, status;

    number = INT32_MIN;

    status = IecStringDecimal(a, sizeof(a), number, 0, '0', 0);

    TEST_ASSERT_EQUAL_STRING("-2147483648", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_decimal_size(void) {
    char a[6];
    int32_t number, status;

    strcpy(a, "abc");
    number = 123456;

    status = IecStringDecimal(a, sizeof(a), number, 0, '0', 0);

    TEST_ASSERT_EQUAL_STRING("abc", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE_INVALID, status);

    TEST_DONE;
}

_TEST test_decimal_null(void) {
    int32_t number, status;

    number = 123456;

    status = IecStringDecimal(NULL, 7, number, 0, '0', 0);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringDecimal zeros", test_decimal_zeros),
    new_TestFixture("IecStringDecimal spaces", test_decimal_spaces),
    new_TestFixture("IecStringDecimal sign positive", test_decimal_sign_pos),
    new_TestFixture("IecStringDecimal tilde", test_decimal_tilde),
    new_TestFixture("IecStringDecimal max", test_decimal_max),
    new_TestFixture("IecStringDecimal min", test_decimal_min),
    new_TestFixture("IecStringDecimal size error", test_decimal_size),
    new_TestFixture("IecStringDecimal null error", test_decimal_null)
};

UNITTEST_CALLER_TEST (decimal_set, "IecStringDecimal test set", fixtures);
