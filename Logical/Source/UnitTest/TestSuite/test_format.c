
#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

_TEST format_basic(void) {
    char a[81], b[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, "Error: %b, Temp: %f C, Step: %i, Message: %s");
    args.b[0] = true;
    args.f[0] = 123.456;
    args.i[0] = 15;
    strcpy(args.s[0], "All clear");

    status = IecStringFormat(a, sizeof(a), b, &args);

    TEST_ASSERT_EQUAL_STRING("Error: TRUE, Temp: 123.456 C, Step: 15, Message: All clear", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST format_bool(void) {
    char a[81], b[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, "%b %b %b %b %b %b %b");
    memset(args.b, 0, sizeof(args.b));
    args.b[1] = true;

    status = IecStringFormat(a, sizeof(a), b, &args);

    TEST_ASSERT_EQUAL_STRING("FALSE TRUE FALSE FALSE FALSE FALSE ", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST format_double(void) {
    char a[81], b[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, "%f, %f, %f, %f");
    args.f[0] = -123;
    args.f[1] = 0.0456;
    args.f[2] = 12e7;
    args.f[3] = 123456789;

    status = IecStringFormat(a, sizeof(a), b, &args);

    TEST_ASSERT_EQUAL_STRING("-123, 0.0456, 1.2e+08, 1.23457e+08", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST format_int(void) {
    char a[81], b[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, "%i, %i, %i, %i, %i");
    args.i[0] = -123;
    args.i[1] = INT32_MAX;
    args.i[2] = INT32_MIN;
    args.i[3] = UINT32_MAX;
    args.i[4] = 2147483648U;

    status = IecStringFormat(a, sizeof(a), b, &args);

    TEST_ASSERT_EQUAL_STRING("-123, 2147483647, -2147483648, -1, -2147483648", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST format_string(void) {
    char a[81], b[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, "%s, %s, %s");
    strcpy(args.s[0], "one");
    strcpy(args.s[1], "two");
    strcpy(args.s[2], "three");

    status = IecStringFormat(a, sizeof(a), b, &args);

    TEST_ASSERT_EQUAL_STRING("one, two, three", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST format_null_source(void) {
    char a[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(a, "Test");

    status = IecStringFormat(a, sizeof(a), NULL, &args);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST format_null_destination(void) {
    char b[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, "Test");

    status = IecStringFormat(NULL, 10, b, &args);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST format_null_values(void) {
    char a[81], b[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringFormat(a, sizeof(a), b, NULL);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST format_size(void) {
    char a[81], b[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(a, "Test");

    status = IecStringFormat(a, 0, b, &args);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE_ZERO, status);

    TEST_DONE;
}

_TEST format_overlap(void) {
    char a[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(a, "Test overlap");

    status = IecStringFormat(a, sizeof(a), a + 5, &args);

    TEST_ASSERT_EQUAL_STRING("Test overlap", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST format_truncate(void) {
    char a[11], b[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, "%s, %s, %s");
    strcpy(args.s[0], "one");
    strcpy(args.s[1], "two");
    strcpy(args.s[2], "three");

    status = IecStringFormat(a, sizeof(a), b, &args);

    TEST_ASSERT_EQUAL_STRING("one, two, ", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFormat basic", format_basic),
    new_TestFixture("IecStringFormat bool", format_bool),
    new_TestFixture("IecStringFormat double", format_double),
    new_TestFixture("IecStringFormat int", format_int),
    new_TestFixture("IecStringFormat string", format_string),
    new_TestFixture("IecStringFormat null source", format_null_source),
    new_TestFixture("IecStringFormat null destination", format_null_destination),
    new_TestFixture("IecStringFormat null values", format_null_values),
    new_TestFixture("IecStringFormat size", format_size),
    new_TestFixture("IecStringFormat overlap", format_overlap),
    new_TestFixture("IecStringFormat truncate", format_truncate)
};

UNITTEST_CALLER_TEST (format_set, "IecStringFormat test set", fixtures);
