
#include <bur/plc.h>
#include <stdint.h>
#include <AsBrStr.h>

void _CYCLIC ProgramCyclic(void)
{
    char a[81];
    int i;
    for (i = 0; i < 100; i++)
        brsstrcpy((uint32_t)a, (uint32_t)"This is a test of string copy performance");
}
