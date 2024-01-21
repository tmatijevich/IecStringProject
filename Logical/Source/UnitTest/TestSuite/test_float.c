#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

#define SAMPLE_SIZE 81
#define FULL_PRECISION 6
#define DEFAULT_WIDTH 0

_TEST test_float_variable(void) {
    char a[SAMPLE_SIZE];
    float value;
    int32_t status;

    value = 12e34f;

    status = IecStringFloat(a, sizeof(a), value, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("1.200000e+35", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_literal(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 12e34f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("1.200000e+35", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_p5(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 123456.7f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("123456.700000", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_p4(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 12345.67f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("12345.670000", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_p3(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 1234.567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("1234.567000", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_p2(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 123.4567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("123.456700", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_p1(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 12.34567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("12.345670", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_0(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 1.234567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("1.234567", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_n1(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.1234567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    /* Rounding */
    TEST_ASSERT_EQUAL_STRING("0.123457", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_n2(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.01234567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    /* Rounding */
    TEST_ASSERT_EQUAL_STRING("0.012346", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_n3(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.001234567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    /* Rounding */
    TEST_ASSERT_EQUAL_STRING("0.001235", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_n4(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.0001234567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("0.000123", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_n5(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.00001234567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("0.000012", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_exponent_n6(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.000001234567f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("0.000001", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_10_5_round(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 123456.7f, 0, 6, 0);

    TEST_ASSERT_EQUAL_STRING("123457", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_2_round(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 123.4567f, 0, 6, 0);

    TEST_ASSERT_EQUAL_STRING("123.457", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n3_round(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.0001239f, 0, 6, 0);

    TEST_ASSERT_EQUAL_STRING("0.000124", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n6_round(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.0000019f, 0, 6, 0);

    TEST_ASSERT_EQUAL_STRING("0.000002", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_5_rollover(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 999999.9f, 0, 6, 0);

    TEST_ASSERT_EQUAL_STRING("1.00000e6", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n1_rollover(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.9999999f, 0, 6, 0);

    TEST_ASSERT_EQUAL_STRING("1.00000", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_float_10_n6_rollover(void) {
    char a[81];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.0000099f, 0, 6, 0);

    TEST_ASSERT_EQUAL_STRING("0.000010", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFloat from variable", test_float_variable),
    new_TestFixture("IecStringFloat from literal", test_float_literal),
    new_TestFixture("IecStringFloat exponent +5", test_float_exponent_p5),
    new_TestFixture("IecStringFloat exponent +4", test_float_exponent_p4),
    new_TestFixture("IecStringFloat exponent +3", test_float_exponent_p3),
    new_TestFixture("IecStringFloat exponent +2", test_float_exponent_p2),
    new_TestFixture("IecStringFloat exponent +1", test_float_exponent_p1),
    new_TestFixture("IecStringFloat exponent  0", test_float_exponent_0),
    new_TestFixture("IecStringFloat exponent -1", test_float_exponent_n1),
    new_TestFixture("IecStringFloat exponent -2", test_float_exponent_n2),
    new_TestFixture("IecStringFloat exponent -3", test_float_exponent_n3),
    new_TestFixture("IecStringFloat exponent -4", test_float_exponent_n4),
    new_TestFixture("IecStringFloat exponent -5", test_float_exponent_n5),
    new_TestFixture("IecStringFloat exponent -6", test_float_exponent_n6),
    new_TestFixture("IecStringFloat 10^5 rounding", test_float_10_5_round),
    new_TestFixture("IecStringFloat 10^2 rounding", test_float_10_2_round),
    new_TestFixture("IecStringFloat 10^-3 rounding", test_float_10_n3_round),
    new_TestFixture("IecStringFloat 10^-6 rounding", test_float_10_n6_round),
    new_TestFixture("IecStringFloat 10^5 rollover", test_float_10_5_rollover),
    new_TestFixture("IecStringFloat 10^-1 rollover", test_float_10_n1_rollover),
    new_TestFixture("IecStringFloat 10^-6 rollover", test_float_10_n6_rollover)
};

UNITTEST_CALLER_TEST(float_set, "IecStringFloat test set", fixtures);
