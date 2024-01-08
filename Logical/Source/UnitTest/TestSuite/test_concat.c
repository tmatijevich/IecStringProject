#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST test_concat_standard(void) {
    char a[81], b[81];
    int32_t status;

    strcpy(a, "Hello");
    strcpy(b, " World!");

    /* Concatenate from variable */
    status = IecStringConcat(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    /* Concatenate from literal */
    strcpy(a, "Hello");
    status = IecStringConcat(a, sizeof(a), " World!");

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_concat_null_source(void) {
    char a[81];
    int32_t status;

    strcpy(a, "Hello World!");

    status = IecStringConcat(a, sizeof(a), NULL);

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST test_concat_null_destination(void) {
    char b[81];
    int32_t status;

    strcpy(b, "Hello World!");

    status = IecStringConcat(NULL, 10, b);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST test_concat_size(void) {
    char a[81], b[81];
    int32_t status;

    strcpy(a, "Hello World!");

    status = IecStringConcat(a, 0, b);

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE, status);

    TEST_DONE;
}

_TEST test_concat_overlap_destination(void) {
    char a[81];
    char* b;
    int32_t status;

    strcpy(a, "Hello");
    b = a + 6;

    status = IecStringConcat(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("Hello", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST test_concat_overlap_source(void) {
    char* a;
    char b[81];
    int32_t status;

    strcpy(b, "Hello World!");
    a = b + 6;

    status = IecStringConcat(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("World!", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST test_concat_truncate(void) {
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
    new_TestFixture("IecStringConcat standard", test_concat_standard),
    new_TestFixture("IecStringConcat null source", test_concat_null_source),
    new_TestFixture("IecStringConcat null destination", 
                    test_concat_null_destination),
    new_TestFixture("IecStringConcat size", test_concat_size),
    new_TestFixture("IecStringConcat overlap destination", 
                    test_concat_overlap_destination),
    new_TestFixture("IecStringConcat overlap source", 
                    test_concat_overlap_source),
    new_TestFixture("IecStringConcat truncate", test_concat_truncate)
};

UNITTEST_CALLER_TEST (concat_set, "IecStringConcat test set", fixtures);
