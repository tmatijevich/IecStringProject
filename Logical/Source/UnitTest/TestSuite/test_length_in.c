#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

_TEST test_length_in_literal(void)
{
    char a[] = "4321abcd";

    /* Call function */
    uint32_t length = IecStringLengthIn(a, "0123456789");

    /* Test immutability */
    TEST_ASSERT_EQUAL_STRING("4321abcd", a);
    /* Test result */
    TEST_ASSERT_EQUAL_INT(4, length);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringLengthIn from literal", test_length_in_literal)
};

UNITTEST_CALLER_TEST(length_in_set, "IecStringLengthIn test set", fixtures);
