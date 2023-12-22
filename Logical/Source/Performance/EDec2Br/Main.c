
#include <bur/plc.h>
#include <stdint.h>
#include <AsBrStr.h>

void _CYCLIC ProgramCyclic(void)
{
    char a[21];
    int32_t i, number = -2001001001;
    for (i = 0; i < 100; i++)
        brsitoa(number, (UDINT)a);
}
