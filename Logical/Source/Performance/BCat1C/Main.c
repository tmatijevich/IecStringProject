
#include <bur/plc.h>
#include <string.h>

void _CYCLIC ProgramCyclic(void)
{
    char a[81] = "Hello World! 1234567890.";
    int i;
    for (i = 0; i < 100; i++) {
        a[19] = '\0';
        strcat(a, " The quick brown fox jumps over the lazy dog.");
    }
}
