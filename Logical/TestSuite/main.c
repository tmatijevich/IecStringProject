
#ifdef _DEFAULT_INCLUDES
    #include <AsDefault.h>
#endif

#include <UnitTest.h>
#include <string.h>

UtMgrTestSuite_typ test_suite;

void _INIT ProgramInit(void)
{
    memset(&test_suite, 0, sizeof(test_suite));
    IecStringCopy(test_suite.Name, sizeof(test_suite.Name), "IecString_Tests");
    IecStringCopy(test_suite.Description, sizeof(test_suite.Description), 
                "Test command and edges cases of all functions");
    test_suite.Type = utMgrTEST_TYPE_C;
    IecStringCopy(test_suite.MetaInformation, 
                sizeof(test_suite.MetaInformation), 
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
