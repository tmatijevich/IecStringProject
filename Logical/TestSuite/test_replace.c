
#ifdef _DEFAULT_INCLUDES
    #include <AsDefault.h>
#endif

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

    status = IecStringReplace(a, sizeof(a), f, r, b);

    TEST_ASSERT_EQUAL_STRING("The slow brown fox", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringReplace basic", replace_basic)
};

UNITTEST_CALLER_TEST (replace_set, "IecStringReplace test set", fixtures);
