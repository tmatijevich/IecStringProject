#include <bur/plc.h>
#include <IecString.h>

char a[255] = "0123456789abcdefghij0123456789abcdefghij"
              "0123456789abcdefghij0123456789abcdefghij";
int i;

/* 100 calls to concatenate 80 characters to length of 80 */
void _CYCLIC ProgramCyclic(void)
{
    for (i = 0; i < 100; i++)
    {
        a[80] = '\0';
        IecStringConcat(a, sizeof(a),
                        "0123456789abcdefghij0123456789abcdefghij"
                        "0123456789abcdefghij0123456789abcdefghij");
    }
}
