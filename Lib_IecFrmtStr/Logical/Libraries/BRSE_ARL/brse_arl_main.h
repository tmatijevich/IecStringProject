/*! \file brse_arl_main.h */

/*! \mainpage BRSE_ARL
	\section Introduction
	\brief This library allows you to write to the built-in AS logbook using a set of function calls in an asynchronous way.

	The syntax of these functions is as similar as possible to the ANSI-C function "printf", as can be seen in the @ref examples.

	The asynchronous behavior is achieved by putting all incoming messages into a local circular buffer.
	This buffer stores the log messages until they are fetched by calling \ref BRSE_ARL_Cyclic() and written to the 
	actual AS logbook using the built-in AS function "AsArLogWrite".
	
	Therefore, the synchronous nature of the "AsArLog" library is completely hidden to the user. 
	
	\anchor buffer
		
	If the buffer is full when the \ref BRSE_ARL_Cyclic() function is called the buffer is automatically locked to avoid data being overwritten. 
	Additionally a message is output in the logger stating "BUFFER RESET STARTED". Thereafter the buffer is emptied to the logger. When
	the buffer is empty a message stating "BUFFER RESET COMPLETED" is output into the logger and the lock of the buffer is released. The function
	\ref BRSE_ARL_Cyclic() only returns zero if the buffer is empty.
	
	The user must be aware that during a buffer reset new entries to the buffer can not be added which results in the possibility of having some data
	inconsistency directly after and before the buffer reset. Typically one buffer entry is lost before the reset start message. Several entries may be
	lost during the buffer reset, depending on how long time it takes to empty the buffer. Data consistency can be trusted between the reset start and
	completed messages. 

	Since the library is using an circular buffer it is possible to continuously logg to the buffer in the DRAM and only dump the buffered
	data to the logger when an error occurs. This saves CPU time since the PLC does not have to transfer that data between the volatile
	and the non-volatile memory during normal operation.
			
	By choosing a unique ID, a specific logbook can be addressed.
	
	\section Overview

	\image html BRSEARLOV.jpg
	
	\section Description 

	Start by setting up and create your logger.
	This is accomplished by the \ref BRSE_ARL_Alloc() function. 
	Here you can set the name of your logger or, if a name is not given, the default user logbook will be used.
	Place \ref BRSE_ARL_Alloc() in the init part of your code.

	Next, you have to call the function \ref BRSE_ARL_Cyclic() in a cyclic way in your code to be able to "empty" the FIFO buffer 
	of all its write-commands to the logbook. 

	Now you can send any of the available messages to the logbook by using \ref BRSE_ARL_Fatal(), \ref BRSE_ARL_Warning(),
	or \ref BRSE_ARL_Info().

	When finished with your logbook you can use the \ref BRSE_ARL_Free() function to empty and close the FIFO buffer.
	Place \ref BRSE_ARL_Free() in the exit part of your code.

	This is an example of logbook output taken from AS.
	If you add your own error numbers, be sure to only use values > 50000, lower values are	reserved for AS.\n

	\image html LOGGBOOK.jpg
*/

#ifndef _BRSE_ARL_MAIN_H
#define _BRSE_ARL_MAIN_H


#ifndef NULL
#define NULL ((void *)0)
#endif

/* Include libraries */
#include <bur/plctypes.h>
#include <sys_lib.h>
#include <ArEventLog.h>
#include <AsBrStr.h>
#include <string.h>

/* Include internal library components */
#include "BRSE_ARL.h"

/* Logger list */
#define BRSE_ARL_MAX_LOGGERS	256
extern BRSE_ARL_Logger_typ* BRSE_ARL_LoggerList[BRSE_ARL_MAX_LOGGERS];

/* Define some basic macros */
#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif
#ifndef ARRAY_ENTRIES
#define ARRAY_ENTRIES(array) (sizeof(array)/sizeof(array[0]))
#endif

/* Define boolean states */
#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/* Define default error constants (if not defined before) */
#ifndef ERR_OK
#define ERR_OK                0
#endif
#ifndef ERR_FUB_ENABLE_FALSE
#define ERR_FUB_ENABLE_FALSE  65534
#endif
#ifndef ERR_FUB_BUSY
#define ERR_FUB_BUSY          65535
#endif

/* ID base value */
#define BRSE_ARL_ID_BASE 0x53450000

/* Define error constants */
#define BRSE_ARL_ID_ALREADY_INITIALIZED	58200
#define BRSE_ARL_ID_NOT_VALID 			58201
#define BRSE_ARL_BUFFER_FULL  			58202
#define BRSE_ARL_OUT_OF_MEMORY          58203

#endif
