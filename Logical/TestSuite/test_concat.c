
#ifdef _DEFAULT_INCLUDES
    #include <AsDefault.h>
#endif

#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST concat_basic(void) {
    char a[81], b[81];
    int32_t status;

    strcpy(a, "Hello");
    strcpy(b, " World!");

    status = IecStringConcat(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST concat_null_source(void) {
    char a[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringConcat(a, sizeof(a), NULL);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST concat_null_destination(void) {
    char b[81];
    int32_t status;

    strcpy(b, "Test");

    status = IecStringConcat(NULL, 10, b);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST concat_size(void) {
    char a[81], b[81];
    int32_t status;

    strcpy(a, "Test");

    status = IecStringConcat(a, 0, b);

    TEST_ASSERT_EQUAL_STRING("Test", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE, status);

    TEST_DONE;
}

_TEST concat_overlap(void) {
    char a[81];
    int32_t status;

    strcpy(a, "Test overlap");

    status = IecStringConcat(a, sizeof(a), a + 5);

    TEST_ASSERT_EQUAL_STRING("Test overlap", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST concat_truncate(void) {
    char a[11], b[81];
    int32_t status;

    strcpy(a, "0123456");
    strcpy(b, "789abc");

    status = IecStringConcat(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("0123456789", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringConcat basic", concat_basic),
    new_TestFixture("IecStringConcat null source", concat_null_source),
    new_TestFixture("IecStringConcat null destination", concat_null_destination),
    new_TestFixture("IecStringConcat size", concat_size),
    new_TestFixture("IecStringConcat overlap", concat_overlap),
    new_TestFixture("IecStringConcat truncate", concat_truncate)
};

UNITTEST_CALLER_TEST (concat_set, "IecStringConcat test set", fixtures);
