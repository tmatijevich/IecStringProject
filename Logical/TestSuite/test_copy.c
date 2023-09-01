
#ifdef _DEFAULT_INCLUDES
    #include <AsDefault.h>
#endif

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

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringCopy basic", copy_basic)
};

UNITTEST_CALLER_TEST (copy_set, "IecStringCopy test set", fixtures);
