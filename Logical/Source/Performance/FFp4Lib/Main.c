#include <bur/plc.h>
#include <IecString.h>

char a[81];
int i;

void _CYCLIC ProgramCyclic(void) {
    for (i = 0; i < 100; i++)
        IecStringFloat(a, sizeof(a), 123.456e-23f);
}
