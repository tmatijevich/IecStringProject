#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

#define SAMPLE_SIZE 81
#define SAMPLE_STRING "Hello World!"
#define LIBRARY_ERROR_NONE 0
#define LARGE_SIZE 1001

_TEST test_copy_variable(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, SAMPLE_STRING);

    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_copy_literal(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringCopy(a, sizeof(a), SAMPLE_STRING);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_copy_empty_source(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    int32_t status;

    /* Initialize a to sample */
    strcpy(a, SAMPLE_STRING);
    strcpy(b, "");

    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("", a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_copy_size_1(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    int32_t status;

    /* Initialize a to sample */
    strcpy(a, SAMPLE_STRING);
    strcpy(b, SAMPLE_STRING);

    status = IecStringCopy(a, 1, b);

    TEST_ASSERT_EQUAL_STRING("", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

_TEST test_copy_size_large(void) {
    char a[LARGE_SIZE], b[LARGE_SIZE];
    int32_t status;

    /* Initialize b */
    memset(b, 'z', LARGE_SIZE - 1);
    b[LARGE_SIZE - 1] = '\0';

    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING(b, a);
    TEST_ASSERT_EQUAL_INT(LIBRARY_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_copy_null_source(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    strcpy(a, SAMPLE_STRING);

    status = IecStringCopy(a, sizeof(a), NULL);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST test_copy_null_destination(void) {
    char b[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, SAMPLE_STRING);

    status = IecStringCopy(NULL, SAMPLE_SIZE, b);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NULL, status);

    TEST_DONE;
}

_TEST test_copy_size_zero(void) {
    char a[SAMPLE_SIZE], b[SAMPLE_SIZE];
    int32_t status;

    /* Initialize a to sample */
    strcpy(a, SAMPLE_STRING);

    status = IecStringCopy(a, 0, b);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_SIZE, status);

    TEST_DONE;
}

_TEST test_copy_overlap_destination(void) {
    char a[SAMPLE_SIZE];
    char* b;
    int32_t status;

    /* Initialize a to sample */
    strcpy(a, SAMPLE_STRING);
    /* Assign source to overlap destination */
    b = a + sizeof(SAMPLE_STRING) / 2;

    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING(SAMPLE_STRING, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST test_copy_overlap_source(void) {
    char* a;
    char b[SAMPLE_SIZE];
    char c[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, SAMPLE_STRING);
    /* Assign destination to overlap source */
    a = b + sizeof(SAMPLE_STRING) / 2;
    strcpy(c, a);

    status = IecStringCopy(a, SAMPLE_SIZE / 2, b);

    TEST_ASSERT_EQUAL_STRING(c, a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_OVERLAP, status);

    TEST_DONE;
}

_TEST test_copy_truncate(void) {
    char a[11], b[SAMPLE_SIZE];
    int32_t status;

    strcpy(b, "0123456789abc");

    status = IecStringCopy(a, sizeof(a), b);

    TEST_ASSERT_EQUAL_STRING("0123456789", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringCopy from variable", test_copy_variable),
    new_TestFixture("IecStringCopy from literal", test_copy_literal),
    new_TestFixture("IecStringCopy empty source", test_copy_empty_source),
    new_TestFixture("IecStringCopy source size 1", test_copy_size_1),
    new_TestFixture("IecStringCopy source size large", test_copy_size_large),
    new_TestFixture("IecStringCopy null source", test_copy_null_source),
    new_TestFixture("IecStringCopy null destination", 
                    test_copy_null_destination),
    new_TestFixture("IecStringCopy zero size", test_copy_size_zero),
    new_TestFixture("IecStringCopy overlap destination", 
                    test_copy_overlap_destination),
    new_TestFixture("IecStringCopy overlap source", test_copy_overlap_source),
    new_TestFixture("IecStringCopy truncate", test_copy_truncate)
};

UNITTEST_CALLER_TEST (copy_set, "IecStringCopy test set", fixtures);
