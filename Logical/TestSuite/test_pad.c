
#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST padint_zeros(void) {
    char a[81];
    int32_t number, status;

    number = 1234;

    status = IecStringPadInt(a, sizeof(a), number, 6, 0);

    TEST_ASSERT_EQUAL_STRING("001234", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST padint_spaces(void) {
    char a[81];
    int32_t number, status;

    number = -5678;

    status = IecStringPadInt(a, sizeof(a), number, 6, 1);

    TEST_ASSERT_EQUAL_STRING("-  5678", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST padint_max(void) {
    char a[81];
    int32_t number, status;

    number = INT32_MAX;

    status = IecStringPadInt(a, sizeof(a), number, 0, 0);

    TEST_ASSERT_EQUAL_STRING("2147483647", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST padint_min(void) {
    char a[81];
    int32_t number, status;

    number = INT32_MIN;

    status = IecStringPadInt(a, sizeof(a), number, 0, 0);

    TEST_ASSERT_EQUAL_STRING("-2147483648", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST padint_size(void) {
    char a[6];
    int32_t number, status;

    strcpy(a, "abc");
    number = 123456;

    status = IecStringPadInt(a, sizeof(a), number, 0, 0);

    TEST_ASSERT_EQUAL_STRING("abc", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE, status);

    TEST_DONE;
}

_TEST padint_null(void) {
    int32_t number, status;

    number = 123456;

    status = IecStringPadInt(NULL, 7, number, 0, 0);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringPadInt zeros", padint_zeros),
    new_TestFixture("IecStringPadInt spaces", padint_spaces),
    new_TestFixture("IecStringPadInt max", padint_max),
    new_TestFixture("IecStringPadInt min", padint_min),
    new_TestFixture("IecStringPadInt size error", padint_size),
    new_TestFixture("IecStringPadInt null error", padint_null)
};

UNITTEST_CALLER_TEST (padint_set, "IecStringPadInt test set", fixtures);
