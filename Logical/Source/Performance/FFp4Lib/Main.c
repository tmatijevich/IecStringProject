#include <bur/plc.h>
#include <IecString.h>

char a[81];
int i;

/* 100 calls to convert float to string */
void _CYCLIC ProgramCyclic(void)
{
    for (i = 0; i < 100; i++)
        IecStringFloat(a, sizeof(a), 123.456e-23f, 0, 6, IECSTRING_FLAG_NONE);
}
