
#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST replace_basic(void) {
    char a[81], b[81], f[81], r[81];
    int32_t status;

    strcpy(b, "The quick brown fox");
    strcpy(f, "quick");
    strcpy(r, "slow");

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING("The slow brown fox", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST replace_multiple(void) {
    char a[81], b[81], f[81], r[81];
    int32_t status;

    strcpy(b, "The quick brown fox");
    strcpy(f, " ");
    strcpy(r, "_");

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING("The_quick_brown_fox", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST replace_null_source(void) {
    char a[81], f[81], r[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringReplace(a, sizeof(a), f, r, NULL);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST replace_null_find(void) {
    char a[81], b[81], r[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringReplace(a, sizeof(a), NULL, r, b);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST replace_null_replace(void) {
    char a[81], b[81], f[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringReplace(a, sizeof(a), f, NULL, b);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST replace_null_destination(void) {
    char b[81], f[81], r[81];
    int32_t status;

    status = IecStringReplace(NULL, 11, b, f, r);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST replace_size(void) {
    char a[81], b[81], f[81], r[81];
    int32_t status;

    strcpy(a, "Test");
    strcpy(b, "The quick brown fox");
    strcpy(f, "quick");
    strcpy(r, "slow");

    status = IecStringReplace(a, 0, b, f, r);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE, status);

    TEST_DONE;
}

_TEST replace_length(void) {
    char a[81], b[81], f[81], r[81];
    int32_t status;

    strcpy(a, "Test");
    strcpy(b, "The quick brown fox");
    strcpy(f, "The quick brown fox jumps");
    strcpy(r, "slow");

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_LENGTH, status);

    TEST_DONE;
}

_TEST replace_overlap_source(void) {
    char a[81], f[81], r[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringReplace(a, sizeof(a), f, r, a + 1);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST replace_overlap_find(void) {
    char a[81], b[81], r[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringReplace(a, sizeof(a), a + 1, r, b);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST replace_overlap_replace(void) {
    char a[81], b[81], f[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringReplace(a, sizeof(a), f, a + 1, b);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST replace_truncate(void) {
    char a[11], b[81], f[81], r[81];
    int32_t status;

    strcpy(b, "The quick brown fox");
    strcpy(f, "quick");
    strcpy(r, "slow");

    status = IecStringReplace(a, sizeof(a), b, f, r);

    TEST_ASSERT_EQUAL_STRING("The slow b", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringReplace basic", replace_basic),
    new_TestFixture("IecStringReplace multiple", replace_multiple),
    new_TestFixture("IecStringReplace null source", replace_null_source),
    new_TestFixture("IecStringReplace null find", replace_null_find),
    new_TestFixture("IecStringReplace null replace", replace_null_replace),
    new_TestFixture("IecStringReplace null destination", replace_null_destination),
    new_TestFixture("IecStringReplace size", replace_size),
    new_TestFixture("IecStringReplace length", replace_length),
    new_TestFixture("IecStringReplace overlap source", replace_overlap_source),
    new_TestFixture("IecStringReplace overlap find", replace_overlap_find),
    new_TestFixture("IecStringReplace overlap replace", replace_overlap_replace),
    new_TestFixture("IecStringReplace truncate", replace_truncate)
};

UNITTEST_CALLER_TEST (replace_set, "IecStringReplace test set", fixtures);
