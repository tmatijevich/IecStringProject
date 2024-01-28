#include <bur/plc.h>
#include <AsBrStr.h>

char a[255] = "0123456789abcdefghij0123456789abcdefghij"
              "0123456789abcdefghij0123456789abcdefghij";
int i;

/* 100 calls to concatenate 80 characters to length of 80 */
void _CYCLIC ProgramCyclic(void)
{
    for (i = 0; i < 100; i++)
    {
        a[80] = '\0';
        brsstrcat((unsigned long)a,
                  (unsigned long)"0123456789abcdefghij0123456789abcdefghij"
                                 "0123456789abcdefghij0123456789abcdefghij");
    }
}
