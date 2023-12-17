
#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST copy_basic(void) {
    char a[81], b[81];
    int32_t status;

    strcpy(b, "Hello World!");

    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST copy_null_source(void) {
    char a[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringCopy(a, sizeof(a), NULL);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST copy_null_destination(void) {
    char b[81];
    int32_t status;

    strcpy(b, "Test");

    status = IecStringCopy(NULL, 10, b);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST copy_size(void) {
    char a[81], b[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringCopy(a, 0, b);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE, status);

    TEST_DONE;
}

_TEST copy_overlap(void) {
    char a[81];
    int32_t status;

    strcpy(a, "Test overlap");

    status = IecStringCopy(a, sizeof(a), a + 5);

    TEST_ASSERT_EQUAL_STRING("Test overlap", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST copy_truncate(void) {
    char a[11], b[81];
    int32_t status;

    strcpy(b, "0123456789abc");

    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("0123456789", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringCopy basic", copy_basic),
    new_TestFixture("IecStringCopy null source", copy_null_source),
    new_TestFixture("IecStringCopy null destination", copy_null_destination),
    new_TestFixture("IecStringCopy size", copy_size),
    new_TestFixture("IecStringCopy overlap", copy_overlap),
    new_TestFixture("IecStringCopy truncate", copy_truncate)
};

UNITTEST_CALLER_TEST (copy_set, "IecStringCopy test set", fixtures);
