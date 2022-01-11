
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#include <stdbool.h>
#include <string.h>

void _INIT ProgramInit(void)
{
	// Runtime values
	formatArgs.b[0] = false; // BOOL
	formatArgs.r[0] = 78.768; // LREAL
	formatArgs.i[0] = -2144327918; // DINT, e.g. Status ID
	strcpy(formatArgs.s[0], "INIT"); // STRING
	
	strcpy(format, "Status %b, Temp %r F, Code %i, State %s");
	
	myNumber = -1234;
	digits = 6;
	spaces = false;
}

void _CYCLIC ProgramCyclic(void)
{
	length = IecFormatString(message, sizeof(message), format, &formatArgs);
	
	IecPadNumber(myNumber, number, digits, spaces);
}

void _EXIT ProgramExit(void)
{
	
}

