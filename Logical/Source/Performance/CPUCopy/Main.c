
#include <bur/plc.h>
#include <bur/plctypes.h>
#include <IecString.h>
#include <AsBrStr.h>
#include <string.h>

_LOCAL UINT count _VAR_INIT(100);

void _CYCLIC ProgramCyclic(void)
{
    char a[81], b[81];
    DINT i;
    IecStringCopy(b, sizeof(b), "This is a test of string copy performance");

    /* Test strcpy */
    for (i = 0; i < count; i++)
        strcpy(a, b);
    
    /* Test brsstrcpy */
    for (i = 0; i < count; i++)
        brsstrcpy((UDINT)a, (UDINT)b);

    /* Test IecStringCopy */
    for (i = 0; i < count; i++)
        IecStringCopy(a, sizeof(a), b);
}
