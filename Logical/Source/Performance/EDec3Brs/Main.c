#include <bur/plc.h>
#include <AsBrStr.h>

char a[21];
int i;
const signed long number = -2001001001;

/* 100 calls to convert integer to string */
void _CYCLIC ProgramCyclic(void)
{
    for (i = 0; i < 100; i++)
        brsitoa(number, (unsigned long)a);
}
