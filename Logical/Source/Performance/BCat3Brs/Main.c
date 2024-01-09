#include <bur/plc.h>
#include <AsBrStr.h>
#include <stdint.h>

char a[255] = "Hello World! 1234567890.";
int i;

void _CYCLIC ProgramCyclic(void) {
    for (i = 0; i < 100; i++) {
        a[24] = '\0';
        brsstrcat((uint32_t)a, (uint32_t)" The quick brown fox jumps over the lazy dog.");
    }
}
