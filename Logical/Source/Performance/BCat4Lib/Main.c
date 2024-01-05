#include <bur/plc.h>
#include <IecString.h>

char a[81] = "Hello World! 1234567890.";
int i;

void _CYCLIC ProgramCyclic(void) {
    for (i = 0; i < 100; i++) {
        a[24] = '\0';
        IecStringConcat(a, sizeof(a), " The quick brown fox jumps over the lazy dog.");
    }
}
