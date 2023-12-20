
#include <bur/plc.h>
#include <bur/plctypes.h>
#include <IecString.h>
#include <AsBrStr.h>

_LOCAL UINT count _VAR_INIT(100);

void _CYCLIC ProgramCyclic(void)
{
    char a[21];
    DINT i, number = -2001001001;
    
    /* Test brsitoa */
    for (i = 0; i < count; i++)
        brsitoa(number, (UDINT)a);

    /* Test IecStringInteger */
    for (i = 0; i < count; i++)
        IecStringInteger(a, sizeof(a), number, 5, '0');
}
