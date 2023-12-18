
#include <bur/plc.h>
#include <stdint.h>
#include <string.h>

_LOCAL float number;
_LOCAL uint32_t data, sign, exponent, fraction;
_LOCAL int32_t int_cast;

void _CYCLIC ProgramCyclic(void)
{
    memcpy(&data, &number, sizeof(data));
    sign = (data >> 31) & 0x1;
    exponent = (data >> 23) & 0xFF;
    fraction = data & 0x7FFFFF;
    int_cast = (int)number;
}
