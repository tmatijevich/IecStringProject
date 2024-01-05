#include <bur/plc.h>
#include <IecString.h>

char a[81];
int i;

void _CYCLIC ProgramCyclic(void) {
    for (i = 0; i < 100; i++)
        IecStringCopy(a, sizeof(a), "This is a test of string copy performance across multiple libraries");
}
