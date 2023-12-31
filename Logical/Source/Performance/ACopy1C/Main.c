
#include <bur/plc.h>
#include <string.h>

void _CYCLIC ProgramCyclic(void)
{
    char a[81];
    int i;
    for (i = 0; i < 100; i++)
        strcpy(a, "This is a test of string copy performance across multiple libraries");
}
