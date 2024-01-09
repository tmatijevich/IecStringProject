#include <bur/plc.h>
#include <AsBrStr.h>

char a[255];
int i;

void _CYCLIC ProgramCyclic(void) {
    for (i = 0; i < 100; i++)
        brsstrcpy((unsigned long)a, (unsigned long)"This is a test of string copy performance across multiple libraries.");
}
