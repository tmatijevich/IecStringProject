#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST test_float_10_5(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 123456.f);

    TEST_ASSERT_EQUAL_STRING("123456", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_4(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 12345.6f);

    TEST_ASSERT_EQUAL_STRING("12345.6", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_3(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 1234.56f);

    TEST_ASSERT_EQUAL_STRING("1234.56", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_2(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 123.456f);

    TEST_ASSERT_EQUAL_STRING("123.456", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_1(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 12.3456f);

    TEST_ASSERT_EQUAL_STRING("12.3456", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_0(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 1.23456f);

    TEST_ASSERT_EQUAL_STRING("1.23456", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFloat 10^5", test_float_10_5),
    new_TestFixture("IecStringFloat 10^4", test_float_10_4),
    new_TestFixture("IecStringFloat 10^3", test_float_10_3),
    new_TestFixture("IecStringFloat 10^2", test_float_10_2),
    new_TestFixture("IecStringFloat 10^1", test_float_10_1),
    new_TestFixture("IecStringFloat 10^0", test_float_10_0)
};

UNITTEST_CALLER_TEST(float_set, "IecStringFloat test set", fixtures);
