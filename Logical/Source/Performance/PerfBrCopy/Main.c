
#include <bur/plc.h>
#include <bur/plctypes.h>
#include <AsBrStr.h>

void _CYCLIC ProgramCyclic(void)
{
    char a[81];
    int i;
    for (i = 0; i < 100; i++)
        brsstrcpy((UDINT)a, "This is a test of string copy performance");
}
