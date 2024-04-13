#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

_TEST test_first_in_literal(void)
{
    char a[] = "abcd4321";

    /* Call function */
    uint32_t address = IecStringFirstIn(a, "0123456789");

    /* Test immutability */
    TEST_ASSERT_EQUAL_STRING("abcd4321", a);
    /* Test result */
    TEST_ASSERT_EQUAL_INT((unsigned)a + 4, address);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringFirstIn from literal", test_first_in_literal)
};

UNITTEST_CALLER_TEST(first_in_set, "IecStringFirstIn test set", fixtures);
