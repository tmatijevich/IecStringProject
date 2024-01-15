#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

#define SAMPLE_SIZE 81
#define SAMPLE_STRING "Red left his red house wearing a red shirt driving a red car"
#define SAMPLE_STRING_FIND "red"
#define SAMPLE_STRING_REPLACE "blue"
#define RESULT_STRING "Red left his blue house wearing a blue shirt driving a blue car"
#define LIBRARY_ERROR_NONE 0
#define LARGE_SIZE 1001
#define ALT_STRING "Hello World!"

_TEST replace_variables(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE], f[SAMPLE_SIZE], r[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, SAMPLE_STRING);
    strcpy(f, SAMPLE_STRING_FIND);
    strcpy(r, SAMPLE_STRING_REPLACE);

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING(RESULT_STRING, a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST replace_literals(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringReplace(a, sizeof(a), SAMPLE_STRING, 
                              SAMPLE_STRING_FIND, SAMPLE_STRING_REPLACE);

    TEST_ASSERT_EQUAL_STRING(RESULT_STRING, a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST replace_empty_source(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringReplace(a, sizeof(a), "", 
                              SAMPLE_STRING_FIND, SAMPLE_STRING_REPLACE);

    TEST_ASSERT_EQUAL_STRING("", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST replace_empty_find(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringReplace(a, sizeof(a), SAMPLE_STRING, 
                              "", SAMPLE_STRING_REPLACE);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST replace_empty_replace(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringReplace(a, sizeof(a), SAMPLE_STRING, 
                              SAMPLE_STRING_FIND, "");

    TEST_ASSERT_EQUAL_STRING("Red left his  house wearing a  shirt driving a  car", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST replace_size_1(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringReplace(a, 1, SAMPLE_STRING, 
                              SAMPLE_STRING_FIND, SAMPLE_STRING_REPLACE);

    TEST_ASSERT_EQUAL_STRING("", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

_TEST replace_size_large(void) {
    char a[LARGE_SIZE], b[LARGE_SIZE], c[LARGE_SIZE];
    int32_t status;

    memset(b, 'x', LARGE_SIZE / 8);
    memset(b + LARGE_SIZE / 8, 'y', LARGE_SIZE / 8);
    memset(b + 2 * LARGE_SIZE / 8, 'x', LARGE_SIZE / 8);
    memset(b + 3 * LARGE_SIZE / 8, 'y', LARGE_SIZE / 8);
    memset(b + 4 * LARGE_SIZE / 8, 'x', LARGE_SIZE / 8);
    memset(b + 5 * LARGE_SIZE / 8, 'y', LARGE_SIZE / 8);
    memset(b + 6 * LARGE_SIZE / 8, 'x', LARGE_SIZE / 8);
    memset(b + 7 * LARGE_SIZE / 8, 'y', LARGE_SIZE / 8);
    b[LARGE_SIZE - 1] = '\0';
    memset(c, 'x', LARGE_SIZE - 1);
    c[LARGE_SIZE - 1] = '\0';

    status = IecStringReplace(a, sizeof(a), b, "y", "x");

    TEST_ASSERT_EQUAL_STRING(c, a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST replace_size_exact(void) {
    char a[6];
    int32_t status;

    status = IecStringReplace(a, sizeof(a), "yy yy yy", "yy", "x");

    TEST_ASSERT_EQUAL_STRING("x x x", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST replace_size_exact_middle_empty(void) {
    char a[6];
    int32_t status;

    status = IecStringReplace(a, sizeof(a), "012yyyyy34", "y", "");

    TEST_ASSERT_EQUAL_STRING("01234", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST replace_size_exact_end_empty(void) {
    char a[6];
    int32_t status;

    status = IecStringReplace(a, sizeof(a), "01234yyyyy", "y", "");

    TEST_ASSERT_EQUAL_STRING("01234", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

_TEST replace_null_source(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, ALT_STRING);

    status = IecStringReplace(a, sizeof(a), NULL, 
                              SAMPLE_STRING_FIND, SAMPLE_STRING_REPLACE);

    TEST_ASSERT_EQUAL_STRING(ALT_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST replace_null_find(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, ALT_STRING);

    status = IecStringReplace(a, sizeof(a), SAMPLE_STRING, 
                              NULL, SAMPLE_STRING_REPLACE);

    TEST_ASSERT_EQUAL_STRING(ALT_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST replace_null_replace(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, ALT_STRING);

    status = IecStringReplace(a, sizeof(a), SAMPLE_STRING, 
                              SAMPLE_STRING_FIND, NULL);

    TEST_ASSERT_EQUAL_STRING(ALT_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST replace_null_destination(void) {
    int32_t status;

    status = IecStringReplace(NULL, SAMPLE_SIZE, SAMPLE_STRING, 
                              SAMPLE_STRING_FIND, SAMPLE_STRING_REPLACE);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST replace_size_zero(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, ALT_STRING);

    status = IecStringReplace(a, 0, SAMPLE_STRING, 
                              SAMPLE_STRING_FIND, SAMPLE_STRING_REPLACE);

    TEST_ASSERT_EQUAL_STRING(ALT_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE_ZERO, status);

    TEST_DONE;
}

_TEST replace_overlap_source(void) {
    char *a, b[SAMPLE_SIZE], f[SAMPLE_SIZE], r[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, SAMPLE_STRING);
    strcpy(f, SAMPLE_STRING_FIND);
    strcpy(r, SAMPLE_STRING_REPLACE);
    a = b + 1;

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, b);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST replace_overlap_find(void) {
    char *a, b[SAMPLE_SIZE], f[SAMPLE_SIZE], r[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, SAMPLE_STRING);
    strcpy(f, SAMPLE_STRING_FIND);
    strcpy(r, SAMPLE_STRING_REPLACE);
    a = f + 1;

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING_FIND, f);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST replace_overlap_replace(void) {
    char *a, b[SAMPLE_SIZE], f[SAMPLE_SIZE], r[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, SAMPLE_STRING);
    strcpy(f, SAMPLE_STRING_FIND);
    strcpy(r, SAMPLE_STRING_REPLACE);
    a = r + 1;

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING_REPLACE, r);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST replace_overlap_destination_source(void) {
    char a[SAMPLE_SIZE], *b, f[SAMPLE_SIZE], r[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, ALT_STRING);
    strcpy(f, SAMPLE_STRING_FIND);
    strcpy(r, SAMPLE_STRING_REPLACE);
    b = a + 1;

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING(ALT_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST replace_overlap_destination_find(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE], *f, r[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, ALT_STRING);
    strcpy(b, SAMPLE_STRING);
    strcpy(r, SAMPLE_STRING_REPLACE);
    f = a + 1;

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING(ALT_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST replace_overlap_destination_replace(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE], f[SAMPLE_SIZE], *r;
    int32_t status;

    strcpy(a, ALT_STRING);
    strcpy(b, SAMPLE_STRING);
    strcpy(f, SAMPLE_STRING_FIND);
    r = a + 1;

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING(ALT_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST replace_truncate(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringReplace(a, 18, SAMPLE_STRING, 
                              SAMPLE_STRING_FIND, SAMPLE_STRING_REPLACE);

    TEST_ASSERT_EQUAL_STRING("Red left his blue", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringReplace variables", replace_variables),
    new_TestFixture("IecStringReplace literals", replace_literals),
    new_TestFixture("IecStringReplace empty source", replace_empty_source),
    new_TestFixture("IecStringReplace empty find", replace_empty_find),
    new_TestFixture("IecStringReplace empty replace", 
                    replace_empty_replace),
    new_TestFixture("IecStringReplace destination size 1", replace_size_1),
    new_TestFixture("IecStringReplace large size", replace_size_large),
    new_TestFixture("IecStringReplace exact size", replace_size_exact),
    new_TestFixture("IecStringReplace exact size replace empty in middle", 
                     replace_size_exact_middle_empty),
    new_TestFixture("IecStringReplace exact size replace empty at end", 
                     replace_size_exact_end_empty),
    new_TestFixture("IecStringReplace null source", replace_null_source),
    new_TestFixture("IecStringReplace null find", replace_null_find),
    new_TestFixture("IecStringReplace null replace", replace_null_replace),
    new_TestFixture("IecStringReplace null destination", 
                    replace_null_destination),
    new_TestFixture("IecStringReplace size zero", replace_size_zero),
    new_TestFixture("IecStringReplace overlap source", replace_overlap_source),
    new_TestFixture("IecStringReplace overlap find", replace_overlap_find),
    new_TestFixture("IecStringReplace overlap replace", 
                     replace_overlap_replace),
    new_TestFixture("IecStringReplace source overlap destination", 
                     replace_overlap_destination_source),
    new_TestFixture("IecStringReplace find overlap destination", 
                     replace_overlap_destination_find),
    new_TestFixture("IecStringReplace replace overlap destination", 
                     replace_overlap_destination_replace),
    new_TestFixture("IecStringReplace truncate", replace_truncate)
};

UNITTEST_CALLER_TEST (replace_set, "IecStringReplace test set", fixtures);
