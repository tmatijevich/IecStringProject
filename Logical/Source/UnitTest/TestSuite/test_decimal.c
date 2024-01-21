#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

#define SAMPLE_SIZE 81

_TEST test_decimal_variable(void) {
    char a[SAMPLE_SIZE];
    int32_t number, status;

    number = 1234;

    status = IecStringDecimal(a, sizeof(a), number, 6, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("001234", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_literal(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), 1234, 6, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("001234", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_pad_zero_pos(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), 1, 11, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("0000000001", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_pad_zero_neg(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), -1, 11, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("-0000000001", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_pad_space_pos(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), 1, 11, IECSTRING_FLAG_SPACES);

    TEST_ASSERT_EQUAL_STRING("         1", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_pad_space_neg(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), -1, 11, IECSTRING_FLAG_SPACES);

    TEST_ASSERT_EQUAL_STRING("-         1", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_sign_pos(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), 123456, 8, IECSTRING_FLAG_SIGN);

    TEST_ASSERT_EQUAL_STRING("+0123456", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_sign_neg(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), -123456, 8, IECSTRING_FLAG_SIGN);

    TEST_ASSERT_EQUAL_STRING("-0123456", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_max(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), INT32_MAX, 0, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("2147483647", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_min(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), INT32_MIN, 0, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("-2147483648", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_unsigned_max(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), UINT32_MAX, 0, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("-1", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_large_width(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDecimal(a, sizeof(a), INT32_MAX, 20, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("2147483647", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_decimal_size_zero(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, "abc");

    status = IecStringDecimal(a, 0, 123, 0, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("abc", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE_ZERO, status);

    TEST_DONE;
}

_TEST test_decimal_size_1(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, "abc");

    status = IecStringDecimal(a, 1, 123, 0, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE_INVALID, status);

    TEST_DONE;
}

_TEST test_decimal_size_invalid(void) {
    char a[4];
    int32_t status;

    strcpy(a, "abc");

    status = IecStringDecimal(a, sizeof(a), 123456, 0, IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_STRING("", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE_INVALID, status);

    TEST_DONE;
}

_TEST test_decimal_null(void) {
    int32_t status;

    status = IecStringDecimal(NULL, SAMPLE_SIZE, 123456, 0, 
                              IECSTRING_FLAG_NONE);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringDecimal from variable", test_decimal_variable),
    new_TestFixture("IecStringDecimal from literal", test_decimal_literal),
    new_TestFixture("IecStringDecimal pad zero positive", 
                    test_decimal_pad_zero_pos),
    new_TestFixture("IecStringDecimal pad zero negative", 
                    test_decimal_pad_zero_neg),
    new_TestFixture("IecStringDecimal pad space positive", 
                    test_decimal_pad_space_pos),
    new_TestFixture("IecStringDecimal pad space negative", 
                    test_decimal_pad_space_neg),
    new_TestFixture("IecStringDecimal sign positive", test_decimal_sign_pos),
    new_TestFixture("IecStringDecimal sign negative", test_decimal_sign_neg),
    new_TestFixture("IecStringDecimal max int", test_decimal_max),
    new_TestFixture("IecStringDecimal min int", test_decimal_min),
    new_TestFixture("IecStringDecimal unsigned max", test_decimal_unsigned_max),
    new_TestFixture("IecStringDecimal large width", test_decimal_large_width),
    new_TestFixture("IecStringDecimal size zero", test_decimal_size_zero),
    new_TestFixture("IecStringDecimal size one", test_decimal_size_1),
    new_TestFixture("IecStringDecimal size invalid", test_decimal_size_invalid),
    new_TestFixture("IecStringDecimal null destination", test_decimal_null)
};

UNITTEST_CALLER_TEST (decimal_set, "IecStringDecimal test set", fixtures);
