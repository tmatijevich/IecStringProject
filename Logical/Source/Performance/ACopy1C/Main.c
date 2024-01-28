#include <bur/plc.h>
#include <string.h>

char a[255];
int i;

/* 100 calls to copy 80 characters */
void _CYCLIC ProgramCyclic(void)
{
    for (i = 0; i < 100; i++)
    {
        strcpy(a, "0123456789abcdefghij0123456789abcdefghij"
                  "0123456789abcdefghij0123456789abcdefghij");
    }
}
