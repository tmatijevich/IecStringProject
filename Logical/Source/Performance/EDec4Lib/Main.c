#include <bur/plc.h>
#include <IecString.h>

char a[21];
int i;
const signed long number = -2001001001;

/* 100 calls to convert integer to string */
void _CYCLIC ProgramCyclic(void)
{
    for (i = 0; i < 100; i++)
        IecStringDecimal(a, sizeof(a), number, 0, IECSTRING_FLAG_NONE);
}
