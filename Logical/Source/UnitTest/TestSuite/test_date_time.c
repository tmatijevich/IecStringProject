#include <UnitTest.h>
#include <IecString.h>
#include <astime.h>
#include <string.h>
#include <stdint.h>

#define SAMPLE_SIZE 81

DTStructure value = {
    .year = 2024,
    .month = 1,
    .day = 9,
    .wday = 2,
    .hour = 13,
    .minute = 4,
    .second = 9,
    .millisec = 55
};

_TEST test_date_time_default(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDateTime(a, sizeof(a), &value, NULL);

    TEST_ASSERT_EQUAL_STRING("2024-01-09 13:04", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

_TEST test_date_time_formal_date(void) {
    char a[SAMPLE_SIZE];
    int32_t status;

    status = IecStringDateTime(a, sizeof(a), &value, "dddd, MMMM d, yyyy");

    TEST_ASSERT_EQUAL_STRING("Tuesday, January 9, 2024", a);
    TEST_ASSERT_EQUAL_INT(IECSTRING_ERROR_NONE, status);

    TEST_DONE;
}

UNITTEST_FIXTURES(fixtures) {
    new_TestFixture("IecStringDateTime default", test_date_time_default),
    new_TestFixture("IecStringDateTime formal date", test_date_time_formal_date)
};

UNITTEST_CALLER_TEST(date_time_set, "IecStringDateTime test set", fixtures);
