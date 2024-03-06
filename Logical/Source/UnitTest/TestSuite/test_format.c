#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define SAMPLE_SIZE 81
#define SAMPLE_STRING "Hello World!"
#define LIBRARY_ERROR_NONE 0

_TEST format_from_variable(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, "Error: %b, Temp: %f C, Step: %i, Message: %s");
    args.b[0] = true;
    args.f[0] = 123.456;
    args.i[0] = 15;
    strcpy(args.s[0], "All clear");

    status = IecStringFormat(a, sizeof(a), b, &args);

    TEST_ASSERT_EQUAL_STRING("Error: TRUE, Temp: 123.456000 C, Step: 15, Message: All clear", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST format_from_literal(void) {
    char a[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    args.b[0] = true;
    args.f[0] = 123.456;
    args.i[0] = 15;
    strcpy(args.s[0], "All clear");

    status = IecStringFormat(a, sizeof(a), 
                             "Error: %b, Temp: %f C, Step: %i, Message: %s", 
                             &args);

    TEST_ASSERT_EQUAL_STRING("Error: TRUE, Temp: 123.456000 C, Step: 15, Message: All clear", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST format_bool(void) {
    char a[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    args.b[0] = true;
    args.b[1] = false;
    args.b[2] = 100;
    args.b[3] = false;
    args.b[4] = true;
    args.b[5] = false;

    status = IecStringFormat(a, sizeof(a), 
                             "%b, %b, %b, %b, %b, %b, %b", &args);

    TEST_ASSERT_EQUAL_STRING("TRUE, FALSE, TRUE, FALSE, TRUE, FALSE, ", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST format_float(void) {
    char a[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    args.f[0] = 123456;
    args.f[1] = 2e34;
    args.f[2] = -567890;
    args.f[3] = 1.234567;
    args.f[4] = -1e23;
    args.f[5] = 0;

    status = IecStringFormat(a, sizeof(a), 
                             "%f, %f, %f, %f, %f, %f, %f", &args);

    TEST_ASSERT_EQUAL_STRING("123456.000000, 2.000000e+34, -567890.000000, 1.234567, -1.000000e+23, 0, ", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST format_int(void) {
    char a[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    args.i[0] = -123;
    args.i[1] = INT32_MAX;
    args.i[2] = INT32_MIN;
    args.i[3] = UINT32_MAX;
    args.i[4] = 2147483648U;
    args.i[5] = 0;

    status = IecStringFormat(a, sizeof(a), "%i, %i, %i, %i, %i, %i, %i", &args);

    TEST_ASSERT_EQUAL_STRING("-123, 2147483647, -2147483648, -1, -2147483648, 0, ", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST format_string(void) {
    char a[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    strcpy(args.s[0], "one");
    strcpy(args.s[1], "two");
    strcpy(args.s[2], "three");
    strcpy(args.s[3], "apple");
    strcpy(args.s[4], "banana");
    strcpy(args.s[5], "carrot");

    status = IecStringFormat(a, sizeof(a), "%s, %s, %s, %s, %s, %s, %s", &args);

    TEST_ASSERT_EQUAL_STRING("one, two, three, apple, banana, carrot, ", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST format_null_source(void) {
    char a[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    strcpy(a, SAMPLE_STRING);

    status = IecStringFormat(a, sizeof(a), NULL, &args);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST format_null_destination(void) {
    char b[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    status = IecStringFormat(NULL, SAMPLE_SIZE, b, &args);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST format_null_values(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, "abc123");
    strcpy(b, SAMPLE_STRING);

    status = IecStringFormat(a, sizeof(a), b, NULL);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST format_size_zero(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    strcpy(a, SAMPLE_STRING);

    status = IecStringFormat(a, 0, b, &args);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE_ZERO, status);

    TEST_DONE;
}

_TEST format_size_1(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    strcpy(a, SAMPLE_STRING);

    status = IecStringFormat(a, 1, b, &args);

    TEST_ASSERT_EQUAL_STRING("", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

_TEST format_size_exact_middle(void) {
    char a[20];
    IecStringFormatType args;
    int32_t status;

    strcpy(args.s[0], "quick");

    status = IecStringFormat(a, sizeof(a), "The %s brown fox", &args);

    TEST_ASSERT_EQUAL_STRING("The quick brown fox", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST format_size_exact_end(void) {
    char a[20];
    IecStringFormatType args;
    int32_t status;

    strcpy(args.s[0], "fox");

    status = IecStringFormat(a, sizeof(a), "The quick brown %s", &args);

    TEST_ASSERT_EQUAL_STRING("The quick brown fox", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST format_overlap_source(void) {
    char *a, b[SAMPLE_SIZE];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, SAMPLE_STRING);
    a = b + 1;

    status = IecStringFormat(a, SAMPLE_SIZE, b, &args);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, b);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST format_overlap_destination(void) {
    char a[SAMPLE_SIZE], *b;
    IecStringFormatType args;
    int32_t status;

    strcpy(a, SAMPLE_STRING);
    b = a + 1;

    status = IecStringFormat(a, sizeof(a), b, &args);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST format_truncate(void) {
    char a[12];
    IecStringFormatType args;
    int32_t status;

    strcpy(args.s[0], "one");
    strcpy(args.s[1], "two");
    strcpy(args.s[2], "three");

    status = IecStringFormat(a, sizeof(a), "%s, %s, %s", &args);

    TEST_ASSERT_EQUAL_STRING("one, two, t", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures){
    new_TestFixture("IecStringFormat from variable", format_from_variable),
    new_TestFixture("IecStringFormat from literal", format_from_literal),
    new_TestFixture("IecStringFormat bool", format_bool),
    new_TestFixture("IecStringFormat float", format_float),
    new_TestFixture("IecStringFormat integer", format_int),
    new_TestFixture("IecStringFormat string", format_string),
    new_TestFixture("IecStringFormat null source", format_null_source),
    new_TestFixture("IecStringFormat null destination",
                    format_null_destination),
    new_TestFixture("IecStringFormat null values", format_null_values),
    new_TestFixture("IecStringFormat size zero", format_size_zero),
    new_TestFixture("IecStringFormat size 1", format_size_1),
    new_TestFixture("IecStringFormat size exact format middle", 
                    format_size_exact_middle),
    new_TestFixture("IecStringFormat size exact format end", 
                    format_size_exact_end),
    new_TestFixture("IecStringFormat overlap source", format_overlap_source),
    new_TestFixture("IecStringFormat overlap destination", 
                    format_overlap_destination),
    new_TestFixture("IecStringFormat truncate", format_truncate)
};

UNITTEST_CALLER_TEST (format_set, "IecStringFormat test set", fixtures);
