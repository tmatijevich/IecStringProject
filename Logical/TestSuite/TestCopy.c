#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#include <UnitTest.h>
#include <IecString.h>
#include <string.h>
#include <stdint.h>

_TEST copy_basic (void)
{
	char string1[81], string2[81];
	uint32_t return_value;
	
	memset(string1, 0, sizeof(string1));
	strcpy(string2, "Hello World!");
	
	return_value = IecStringCopy(string1, string2, sizeof(string1));
	
	TEST_ASSERT_EQUAL_STRING("Hello World!", string1);
	TEST_ASSERT_EQUAL_INT((uint32_t)&string1, return_value);
	
	TEST_DONE;
}

_TEST copy_null (void) 
{
	char string1[81], string2[81];
	uint32_t return_value;
	
	memset(string1, 0, sizeof(string1));
	
	return_value = IecStringCopy(string1, NULL, sizeof(string1));
	
	/* Return destination and do not write to destination */
	TEST_ASSERT_EQUAL_STRING("", string1);
	TEST_ASSERT_EQUAL_INT((uint32_t)&string1, return_value);
	
	return_value = IecStringCopy(NULL, string2, sizeof(string1));
	
	/* Return destination even if null */
	TEST_ASSERT_EQUAL_INT(NULL, return_value);
	
	TEST_DONE;
}

_TEST copy_zero (void)
{
	char string1[81], string2[81];
	uint32_t return_value;
	
	strcpy(string1, "Test");
	strcpy(string2, "Zero");
	
	return_value = IecStringCopy(string1, string2, 0);
	
	/* Abort copy if size is zero and do not write to destination */
	TEST_ASSERT_EQUAL_STRING("Test", string1);
	TEST_ASSERT_EQUAL_INT((uint32_t)&string1, return_value);
	
	TEST_DONE;
}

_TEST copy_one (void)
{
	char string1[81], string2[81];
	
	strcpy(string1, "Test");
	strcpy(string2, "Zero");
	
	IecStringCopy(string1, string2, 1);
	
	/* Copy one null character */
	TEST_ASSERT_EQUAL_STRING("", string1);
	
	TEST_DONE;
}

_TEST copy_partial (void)
{
	char string1[81], string2[81];
	
	memset(string1, 0, sizeof(string1));
	strcpy(string2, "Hello World!");
	
	IecStringCopy(string1, string2, 6);
	
	TEST_ASSERT_EQUAL_STRING("Hello", string1);
	
	TEST_DONE;
}

_TEST copy_overflow (void)
{
	char string1[6], string2[11];
	
	memset(string1, 0, sizeof(string1));
	strcpy(string2, "IecString");
	
	IecStringCopy(string1, string2, sizeof(string1));
	
	TEST_ASSERT_EQUAL_STRING("IecSt", string1);
	
	TEST_DONE;
}

UNITTEST_FIXTURES (fixtures)
{
	new_TestFixture("IecStringCopy basic", copy_basic),
	new_TestFixture("IecStringCopy null", copy_null),
	new_TestFixture("IecStringCopy zero", copy_zero),
	new_TestFixture("IecStringCopy one", copy_one),
	new_TestFixture("IecStringCopy partial", copy_partial),
	new_TestFixture("IecStringCopy overflow", copy_overflow)
};

UNITTEST_CALLER_TEST (copy_set, "IecStringCopy test set", fixtures);
