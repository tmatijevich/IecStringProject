
#ifdef _DEFAULT_INCLUDES
    #include <AsDefault.h>
#endif

#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

_TEST format_basic(void) {
    char a[81], b[81];
    IecStringFormatType args;
    int32_t status;

    strcpy(b, "Error: %b, Temp: %f C, Step: %i, Message: %s");
    args.b[0] = true;
    args.f[0] = 123.456;
    args.i[0] = 15;
    strcpy(args.s[0], "All clear");

    status = IecStringFormat(a, sizeof(a), b, &args);

    TEST_ASSERT_EQUAL_STRING("Error: TRUE, Temp: 123.456 C, Step: 15, Message: All clear", a);
    TEST_ASSERT_EQUAL_INT(0, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFormat basic", format_basic)
};

UNITTEST_CALLER_TEST (format_set, "IecStringFormat test set", fixtures);
