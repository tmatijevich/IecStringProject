#include "brse_arl_main.h"

void BRSE_ARL_DebugInfo(struct BRSE_ARL_DebugInfo* inst)
{
	/* Check if ID is valid */
	if ((inst->ID >= BRSE_ARL_MAX_LOGGERS) 
		|| (BRSE_ARL_LoggerList[inst->ID] == NULL)
		|| (BRSE_ARL_LoggerList[inst->ID]->ID != (BRSE_ARL_ID_BASE | (unsigned long)inst->ID)))
	{
		inst->Status = BRSE_ARL_ID_NOT_VALID;
		return;
	}

	/* Copy the debug information */
 	memcpy(&inst->Info, &BRSE_ARL_LoggerList[inst->ID], sizeof(inst->Info));
	inst->Status = 0;
}
