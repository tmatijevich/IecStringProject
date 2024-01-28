#include <bur/plc.h>
#include <IecString.h>

char a[255];
int i;

/* 100 calls to copy 80 characters */
void _CYCLIC ProgramCyclic(void)
{
    for (i = 0; i < 100; i++)
    {
        IecStringCopy(a, sizeof(a), "0123456789abcdefghij0123456789abcdefghij"
                                    "0123456789abcdefghij0123456789abcdefghij");
    }
}
