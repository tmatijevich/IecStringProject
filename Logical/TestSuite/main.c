
#include <UnitTest.h>
#include <UtMgr.h>
#include <string.h>

UtMgrTestSuite_typ test_suite;

void _INIT ProgramInit(void)
{
    memset(&test_suite, 0, sizeof(test_suite));
    strcpy(test_suite.Name, "IecString_Tests");
    strcpy(test_suite.Description, 
            "Test common and edges cases of all functions");
    test_suite.Type = utMgrTEST_TYPE_C;
    strcpy(test_suite.MetaInformation, 
            "Test cases for IecString library");
    utInit(&test_suite);
}

void _CYCLIC ProgramCyclic(void)
{
    utCyclic(&test_suite);
}

void _EXIT ProgramExit(void)
{
    utExit(&test_suite);
}
