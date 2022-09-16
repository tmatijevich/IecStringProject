#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#include <UnitTest.h>
#include <string.h>

void _INIT ProgramInit (void)
{
	strcpy(TestSuite.Name, "IecString_Tests");
	strcpy(TestSuite.Description, "Test common and edge cases of all IecString functions");
	TestSuite.Type = utMgrTEST_TYPE_C;
	strcpy(TestSuite.MetaInformation, "Test cases for IecString functions");
	utInit(&TestSuite);
}

void _CYCLIC ProgramCyclic (void)
{
	utCyclic(&TestSuite);
}

void _EXIT ProgramExit (void)
{
	utExit(&TestSuite);
}
