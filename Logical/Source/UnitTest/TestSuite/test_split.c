#include <UnitTest.h>
#include <IecString.h>
#include <stdint.h>
#include <string.h>

_TEST test_split_variable(void)
{
    char a[] = "The quick brown fox jumps over the lazy dog";
    char delimeters[] = " ";
    char b[5][10] = {{0}};
    int32_t result[5] = {0};
    char *address = a, *next_address = 0;
    int i = 0;

    /* Call the function with variable arguments */
    do
    {
        result[i] = IecStringSplit(b[i], sizeof(b[i]), address, delimeters, 
                                   (uint32_t*)&next_address);
        address = next_address;
    }
    while (++i < 5 && next_address);

    TEST_ASSERT_EQUAL_STRING("The quick brown fox jumps over the lazy dog", a);

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

_TEST test_split_multiple(void)
{
    char a[] = "... Apple, Banana, Orange, ...";
    char delimeters[] = " ,.";
    char b[3][10] = {{0}};
    int32_t result[3] = {0};
    char *address = a, *next_address = 0;
    int i = 0;

    /* Call the function with variable arguments */
    do
    {
        result[i] = IecStringSplit(b[i], sizeof(b[i]), address, delimeters, 
                                   (uint32_t*)&next_address);
        address = next_address;
    }
    while (++i < 3 && next_address);

    TEST_ASSERT_EQUAL_STRING("... Apple, Banana, Orange, ...", a);

    TEST_ASSERT_EQUAL_STRING("Apple", b[0]);
    TEST_ASSERT_EQUAL_STRING("Banana", b[1]);
    TEST_ASSERT_EQUAL_STRING("Orange", b[2]);

    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, result[0]);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, result[1]);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, result[2]);

    TEST_DONE;
}

_TEST test_split_truncate(void)
{
    char a[] = "Three, two, one";
    char delimeters[] = " ,";
    char b[4];
    char *next_address;
    int32_t result;

    /* Call the function */
    result = IecStringSplit(b, sizeof(b), a, delimeters, (uint32_t*)&next_address);

    TEST_ASSERT_EQUAL_STRING("Three, two, one", a);

    TEST_ASSERT_EQUAL_STRING("Thr", b);

    TEST_ASSERT_EQUAL_INT(IECSTRING_WARNING_TRUNCATE, result);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringSplit from variable", test_split_variable),
    new_TestFixture("IecStringSplit multiple delimeters", test_split_multiple),
    new_TestFixture("IecStringSplit truncate output", test_split_truncate)
};

UNITTEST_CALLER_TEST(split_set, "IecStringSplit test set", fixtures);
