#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST test_copy_standard(void) {
    char a[81], b[81];
    int32_t status;

    strcpy(b, "Hello World!");

    /* Copy from local variable */
    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    /* Copy from literal */
    status = IecStringCopy(a, sizeof(a), "Hello World!");

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

_TEST test_copy_null_source(void) {
    char a[81];
    int32_t status;

    strcpy(a, "Hello World!");

    status = IecStringCopy(a, sizeof(a), NULL);

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST test_copy_null_destination(void) {
    char b[81];
    int32_t status;

    strcpy(b, "Test");

    status = IecStringCopy(NULL, 10, b);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST test_copy_size(void) {
    char a[81], b[81];
    int32_t status;

    strcpy(a, "Hello World!");

    status = IecStringCopy(a, 0, b);

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE, status);

    TEST_DONE;
}

_TEST test_copy_overlap_destination(void) {
    char a[81];
    char* b;
    int32_t status;

    strcpy(a, "Hello World!");
    b = a + 6;

    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("Hello World!", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST test_copy_overlap_source(void) {
    char* a;
    char b[81];
    int32_t status;

    strcpy(b, "Hello World!");
    a = b + 6;

    status = IecStringCopy(a, 6, b);

    TEST_ASSERT_EQUAL_STRING("World!", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST test_copy_truncate(void) {
    char a[11], b[81];
    int32_t status;

    strcpy(b, "0123456789abc");

    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("0123456789", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringCopy standard", test_copy_standard),
    new_TestFixture("IecStringCopy null source", test_copy_null_source),
    new_TestFixture("IecStringCopy null destination", 
                    test_copy_null_destination),
    new_TestFixture("IecStringCopy size", test_copy_size),
    new_TestFixture("IecStringCopy overlap destination", 
                    test_copy_overlap_destination),
    new_TestFixture("IecStringCopy overlap source", test_copy_overlap_source),
    new_TestFixture("IecStringCopy truncate", test_copy_truncate)
};

UNITTEST_CALLER_TEST (copy_set, "IecStringCopy test set", fixtures);
