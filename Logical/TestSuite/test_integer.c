
#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST integer_zeros(void) {
    char a[81];
    int32_t number, status;

    number = 1234;

    status = IecStringInteger(a, sizeof(a), number, 6, 0);

    TEST_ASSERT_EQUAL_STRING("001234", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST integer_spaces(void) {
    char a[81];
    int32_t number, status;

    number = -5678;

    status = IecStringInteger(a, sizeof(a), number, 6, 1);

    TEST_ASSERT_EQUAL_STRING("-  5678", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST integer_max(void) {
    char a[81];
    int32_t number, status;

    number = INT32_MAX;

    status = IecStringInteger(a, sizeof(a), number, 0, 0);

    TEST_ASSERT_EQUAL_STRING("2147483647", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST integer_min(void) {
    char a[81];
    int32_t number, status;

    number = INT32_MIN;

    status = IecStringInteger(a, sizeof(a), number, 0, 0);

    TEST_ASSERT_EQUAL_STRING("-2147483648", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST integer_size(void) {
    char a[6];
    int32_t number, status;

    strcpy(a, "abc");
    number = 123456;

    status = IecStringInteger(a, sizeof(a), number, 0, 0);

    TEST_ASSERT_EQUAL_STRING("abc", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE, status);

    TEST_DONE;
}

_TEST integer_null(void) {
    int32_t number, status;

    number = 123456;

    status = IecStringInteger(NULL, 7, number, 0, 0);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringInteger zeros", integer_zeros),
    new_TestFixture("IecStringInteger spaces", integer_spaces),
    new_TestFixture("IecStringInteger max", integer_max),
    new_TestFixture("IecStringInteger min", integer_min),
    new_TestFixture("IecStringInteger size error", integer_size),
    new_TestFixture("IecStringInteger null error", integer_null)
};

UNITTEST_CALLER_TEST (integer_set, "IecStringInteger test set", fixtures);
