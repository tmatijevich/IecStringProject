#include <bur/plc.h>
#include <string.h>

char a[81] = "Hello World! 1234567890.";
int i;

void _CYCLIC ProgramCyclic(void) {
    for (i = 0; i < 100; i++) {
        a[24] = '\0';
        strcat(a, " The quick brown fox jumps over the lazy dog.");
    }
}
