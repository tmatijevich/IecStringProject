#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>
#include <float.h>

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

_TEST test_float_rollover_p5(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 999999.95f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("1.000000e+06", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_rollover_p2(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 999.99995f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("1000.000000", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_rollover_0(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.99999995f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("1.000000", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_rollover_n3(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.00099999995f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("0.001000", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_rollover_n6(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.00000099999995f, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("0.000001", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_precision_3(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.123456f, 
                            DEFAULT_WIDTH, 3, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("0.123", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_precision_3_round(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 0.9995f, 
                            DEFAULT_WIDTH, 3, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("1.000", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_precision_0(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 123.456f, 
                            DEFAULT_WIDTH, 0, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("123", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_precision_0_round(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 1.5f, 
                            DEFAULT_WIDTH, 0, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("2", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_precision_0_notation(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), 1.5e20f, 
                            DEFAULT_WIDTH, 0, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("2e+20", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_max(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), FLT_MAX, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("3.402824e+38", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_float_min(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringFloat(a, sizeof(a), FLT_MIN, 
                            DEFAULT_WIDTH, FULL_PRECISION, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("1.175494e-38", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

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
    new_TestFixture("IecStringFloat rollover +5", test_float_rollover_p5),
    new_TestFixture("IecStringFloat rollover +2", test_float_rollover_p2),
    new_TestFixture("IecStringFloat rollover  0", test_float_rollover_0),
    new_TestFixture("IecStringFloat rollover -3", test_float_rollover_n3),
    new_TestFixture("IecStringFloat rollover -6", test_float_rollover_n6),
    new_TestFixture("IecStringFloat precision 3", test_float_precision_3),
    new_TestFixture("IecStringFloat precision 3 round", 
                    test_float_precision_3_round),
    new_TestFixture("IecStringFloat precision 0", test_float_precision_0),
    new_TestFixture("IecStringFloat precision 0 round", 
                    test_float_precision_0_round),
    new_TestFixture("IecStringFloat precision 0 scientific notation", 
                    test_float_precision_0_notation),
    new_TestFixture("IecStringFloat max", test_float_max),
    new_TestFixture("IecStringFloat min", test_float_min)
};

UNITTEST_CALLER_TEST(float_set, "IecStringFloat test set", fixtures);
