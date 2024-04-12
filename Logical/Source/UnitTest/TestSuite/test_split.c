#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

#define STRING_SAMPLE "The quick brown fox jumps over the lazy dog"

_TEST test_split_variable(void)
{
    char a[] = STRING_SAMPLE;
    char delimeters[] = " ";
    char b[5][10] = {{0}};
    int32_t result[5] = {0};
    char *address = a, *next_address = 0;
    int i = 0;

    /* Call the function with variable arguments */
    do
    {
        result[i] = IecStringSplit(b[i], sizeof(b[i]), address, delimeters, 
                                   &next_address);
        address = next_address;
    }
    while (++i < 5 && next_address);

    TEST_ASSERT_EQUAL_STRING("The", b[0]);
    TEST_ASSERT_EQUAL_STRING("quick", b[1]);
    TEST_ASSERT_EQUAL_STRING("brown", b[2]);
    TEST_ASSERT_EQUAL_STRING("fox", b[3]);
    TEST_ASSERT_EQUAL_STRING("jumps", b[4]);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, result[0]);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, result[1]);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, result[2]);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, result[3]);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, result[4]);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringSplit from variable", test_split_variable)
};

UNITTEST_CALLER_TEST(split_set, "IecStringSplit test set", fixtures);
