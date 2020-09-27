(*******************************************************************************
 * Copyright: B&R Industrial Automation
 * Author:    Tyler Matijevich
 * Created:   September 27, 2020/11:19 
********************************************************************************
 * Description: Example program for formatting string in IEC code and logging 
 user entries in the logger
********************************************************************************)

PROGRAM _INIT
	
	// Allocates the FIFO buffer for the logger
	AllocationReturnStatus := BRSE_ARL_Alloc(ID := 1, Name := 'AppLog', LogbookSize := 10000, MessageSize := STR_LEN_ALARM_MSG, BufferedEntries := 25);

END_PROGRAM

PROGRAM _CYCLIC
	
	// Flush pending entries to the logbook
	CyclicReturnStatus := BRSE_ARL_Cyclic(ID := 1);
	
END_PROGRAM

PROGRAM _EXIT
	
	// Deallocate the FIFO buffer
	FreeReturnStatus := BRSE_ARL_Free(ID := 1);

END_PROGRAM
