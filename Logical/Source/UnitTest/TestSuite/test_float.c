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

_TEST test_float_10_n1(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.123456f);

    TEST_ASSERT_EQUAL_STRING("0.123456", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n2(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.012345f);

    TEST_ASSERT_EQUAL_STRING("0.012345", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n3(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.001234f);

    TEST_ASSERT_EQUAL_STRING("0.001234", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n4(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.000123f);

    TEST_ASSERT_EQUAL_STRING("0.000123", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n5(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.000012f);

    TEST_ASSERT_EQUAL_STRING("0.000012", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n6(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.000001f);

    TEST_ASSERT_EQUAL_STRING("0.000001", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_5_round(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 123456.7f);

    TEST_ASSERT_EQUAL_STRING("123457", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_2_round(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 123.4567f);

    TEST_ASSERT_EQUAL_STRING("123.457", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n3_round(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.0001239f);

    TEST_ASSERT_EQUAL_STRING("0.000124", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n6_round(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.0000019f);

    TEST_ASSERT_EQUAL_STRING("0.000002", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_5_rollover(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 999999.9f);

    TEST_ASSERT_EQUAL_STRING("1.00000e6", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n1_rollover(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.9999999f);

    TEST_ASSERT_EQUAL_STRING("1.00000", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n6_rollover(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.0000099f);

    TEST_ASSERT_EQUAL_STRING("0.000010", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFloat 10^5", test_float_10_5),
    new_TestFixture("IecStringFloat 10^4", test_float_10_4),
    new_TestFixture("IecStringFloat 10^3", test_float_10_3),
    new_TestFixture("IecStringFloat 10^2", test_float_10_2),
    new_TestFixture("IecStringFloat 10^1", test_float_10_1),
    new_TestFixture("IecStringFloat 10^0", test_float_10_0),
    new_TestFixture("IecStringFloat 10^-1", test_float_10_n1),
    new_TestFixture("IecStringFloat 10^-2", test_float_10_n2),
    new_TestFixture("IecStringFloat 10^-3", test_float_10_n3),
    new_TestFixture("IecStringFloat 10^-4", test_float_10_n4),
    new_TestFixture("IecStringFloat 10^-5", test_float_10_n5),
    new_TestFixture("IecStringFloat 10^-6", test_float_10_n6),
    new_TestFixture("IecStringFloat 10^5 rounding", test_float_10_5_round),
    new_TestFixture("IecStringFloat 10^2 rounding", test_float_10_2_round),
    new_TestFixture("IecStringFloat 10^-3 rounding", test_float_10_n3_round),
    new_TestFixture("IecStringFloat 10^-6 rounding", test_float_10_n6_round),
    new_TestFixture("IecStringFloat 10^5 rollover", test_float_10_5_rollover),
    new_TestFixture("IecStringFloat 10^-1 rollover", test_float_10_n1_rollover),
    new_TestFixture("IecStringFloat 10^-6 rollover", test_float_10_n6_rollover)
};

UNITTEST_CALLER_TEST(float_set, "IecStringFloat test set", fixtures);
