#include <bur/plc.h>
#include <string.h>

char a[81];
int i;

void _CYCLIC ProgramCyclic(void) {
    for (i = 0; i < 100; i++)
        strcpy(a, "This is a test of string copy performance across multiple libraries.");
}
