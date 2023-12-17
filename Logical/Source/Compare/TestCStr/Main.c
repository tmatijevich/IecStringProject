
#include <bur/plc.h>
#include <string.h>
#include <stdint.h>

_LOCAL uint8_t a[11];
_LOCAL uint8_t b[21];

_LOCAL uint8_t num_copy _VAR_INIT(5);
_LOCAL uint8_t num_concat _VAR_INIT(5);

_LOCAL uint8_t copy;
_LOCAL uint8_t concat;
_LOCAL uint8_t init;

void _INIT ProgramInit(void)
{
	uint8_t i;
	
	for (i = 0; i < sizeof(a) - 1; i++)
		a[i] = i;
	a[sizeof(a) - 1] = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	uint8_t i;
	
	if (copy) {
		copy = 0;
		strncpy((char*)a, (char*)b, num_copy);
	}
	
	if (concat) {
		concat = 0;
		strncat((char*)a, (char*)b, num_concat);
	}
	
	if (init) {
		init = 0;
		for (i = 0; i < sizeof(a) - 1; i++)
			a[i] = i;
		a[sizeof(a) - 1] = 0;	
	}
}

void _EXIT ProgramExit(void)
{

}

