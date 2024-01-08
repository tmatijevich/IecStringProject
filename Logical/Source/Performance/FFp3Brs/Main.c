#include <bur/plc.h>
#include <AsBrStr.h>

char a[81];
int i;

void _CYCLIC ProgramCyclic(void) {
    for (i = 0; i < 100; i++)
        brsftoa(123.456e-23f, (unsigned long)a);
}
