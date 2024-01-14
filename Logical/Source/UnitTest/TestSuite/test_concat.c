#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

#define SAMPLE_STRING_START "Hello"
#define SAMPLE_STRING_END " World!"
#define SAMPLE_SIZE 81
#define LIBRARY_ERROR_NONE 0
#define LARGE_SIZE 1001

_TEST test_concat_variable(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, SAMPLE_STRING_START);
    strcpy(b, SAMPLE_STRING_END);

    status = IecStringConcat(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING_START SAMPLE_STRING_END, a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_concat_literal(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, SAMPLE_STRING_START);

    status = IecStringConcat(a, sizeof(a), SAMPLE_STRING_END);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING_START SAMPLE_STRING_END, a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_concat_size_1(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, "");
    strcpy(b, SAMPLE_STRING_END);

    status = IecStringConcat(a, 1, b);

    TEST_ASSERT_EQUAL_STRING("", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

_TEST test_concat_size_large(void) {
    char a[SAMPLE_SIZE + LARGE_SIZE], b[LARGE_SIZE];
    int32_t status;

    strcpy(a, SAMPLE_STRING_START);
    
    /* Initialize b */
    memset(b, 'z', LARGE_SIZE - 1);
    b[LARGE_SIZE - 1] = '\0';

    status = IecStringConcat(a, sizeof(a), b);

    /* I don't have a good way to assert this
    if the test runs without crashing, that's good */

    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_concat_size_exact(void) {
    char a[sizeof(SAMPLE_STRING_START) + 10];
    int32_t status;

    strcpy(a, SAMPLE_STRING_START);

    status = IecStringConcat(a, sizeof(a), "0123456789");

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING_START "0123456789", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_concat_size_invalid(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, SAMPLE_STRING_START);
    strcpy(b, SAMPLE_STRING_END);

    status = IecStringConcat(a, sizeof(SAMPLE_STRING_START) - 1, b);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING_START, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE_INVALID, status);

    TEST_DONE;
}

_TEST test_concat_null_source(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, SAMPLE_STRING_START);

    status = IecStringConcat(a, sizeof(a), NULL);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING_START, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST test_concat_null_destination(void) {
    char b[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, SAMPLE_STRING_END);

    status = IecStringConcat(NULL, SAMPLE_SIZE, b);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST test_concat_size_zero(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, SAMPLE_STRING_START);
    strcpy(b, SAMPLE_STRING_END);

    status = IecStringConcat(a, 0, b);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING_START, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE_ZERO, status);

    TEST_DONE;
}

_TEST test_concat_overlap_destination(void) {
    char a[SAMPLE_SIZE];
    char* b;
    int32_t status;

    strcpy(a, SAMPLE_STRING_START);
    /* Assign source to overlap destination */
    b = a + sizeof(SAMPLE_STRING_START) / 2;

    status = IecStringConcat(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING_START, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST test_concat_overlap_source(void) {
    char* a;
    char b[SAMPLE_SIZE];
    char c[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, SAMPLE_STRING_END);
    /* Assign destination to overlap source */
    a = b + sizeof(SAMPLE_STRING_END) / 2;
    strcpy(c, a);

    status = IecStringConcat(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING(c, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST test_concat_truncate(void) {
    char a[11], b[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, "0123456");
    strcpy(b, "789abc");

    status = IecStringConcat(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("0123456789", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringConcat from variable", test_concat_variable),
    new_TestFixture("IecStringConcat from literal", test_concat_literal),
    new_TestFixture("IecStringConcat destination size 1", test_concat_size_1),
    new_TestFixture("IecStringConcat large size", test_concat_size_large),
    new_TestFixture("IecStringConcat exact size", test_concat_size_exact),
    new_TestFixture("IecStringConcat invalid size", test_concat_size_invalid),
    new_TestFixture("IecStringConcat null source", test_concat_null_source),
    new_TestFixture("IecStringConcat null destination", 
                    test_concat_null_destination),
    new_TestFixture("IecStringConcat size zero", test_concat_size_zero),
    new_TestFixture("IecStringConcat overlap destination", 
                    test_concat_overlap_destination),
    new_TestFixture("IecStringConcat overlap source", 
                    test_concat_overlap_source),
    new_TestFixture("IecStringConcat truncate", test_concat_truncate)
};

UNITTEST_CALLER_TEST (concat_set, "IecStringConcat test set", fixtures);
