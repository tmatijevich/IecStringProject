
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
	#include <stdbool.h>
	#include <string.h>
#endif

void _INIT ProgramInit(void)
{
	// Runtime values
	formatArgs.b[0] = false; // BOOL
	formatArgs.r[0] = 78.768; // LREAL
	formatArgs.i[0] = -2144327918; // DINT, e.g. Status ID
	strcpy(formatArgs.s[0], "INIT"); // STRING
	
	strcpy(formatMessage, "Status %b, Temp %r F, Code %i, State %s");
}

void _CYCLIC ProgramCyclic(void)
{
	messageLength = IecFormatString(0, sizeof(message), formatMessage, &formatArgs);
}

void _EXIT ProgramExit(void)
{
	
}

