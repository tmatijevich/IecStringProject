/*! \file brse_arl_alloc.c */

#include "brse_arl_main.h"

/* List of all available loggers */
BRSE_ARL_Logger_typ* BRSE_ARL_LoggerList[BRSE_ARL_MAX_LOGGERS];


/*! \interface BRSE_ARL_Alloc
	\brief Allocates the FIFO buffer for the logger
	
	This function allocates a FIFO buffer of the given size to be used for further
	buffered logbook writing functions. It also takes parameters that will be used in \ref BRSE_ARL_Cyclic().
	NOTE: Should be called in the _INIT part of a task!

	The following is done in \ref BRSE_ARL_Cyclic(): If logbook does not exist a new one will be created with the supplied name. 
	If no name has been supplied, the default user logbook will be used.

	\param ID Logger ID of the logbook to be written to
    \param Name Name of the logbook to which to write to.
    \param LogbookSize Size of the logbook in bytes (if a new one has to be created). Note: at least 4096
    \param MessageSize Maximum length of a single message string for the logbook
    \param BufferedEntries Maximum number of messages that can be stored in the FIFO buffer
    \retval \c 0 Function call successful 
*/
unsigned short BRSE_ARL_Alloc(unsigned short ID, plcstring* Name, unsigned long LogbookSize, unsigned long MessageSize, unsigned long BufferedEntries)
{
	BRSE_ARL_Logger_typ* pLogger;
	unsigned long EntrySize;
	unsigned long LoggerTypSize;

	/* Check if ID is in range */
	if (ID >= BRSE_ARL_MAX_LOGGERS)
	{
		return BRSE_ARL_ID_NOT_VALID;
	}
	
	/* Access the chosen logger */
	pLogger = BRSE_ARL_LoggerList[ID];

	/* Check, if ID is valid */
	if ((pLogger != NULL) && (pLogger->ID == (BRSE_ARL_ID_BASE | (unsigned long)ID)))
	{
		return BRSE_ARL_ID_ALREADY_INITIALIZED;
	}

	/* ID is not used yet, so allocate memory for it */

	/* Calculate the entry size and the logger size */
	EntrySize = (unsigned long)sizeof(BRSE_ARL_LogbookEntry_typ) + MessageSize + 1;
	LoggerTypSize = (unsigned long)sizeof(BRSE_ARL_Logger_typ) + BufferedEntries * EntrySize;

	/* Allocate memory for the logger */
	if (TMP_alloc(LoggerTypSize, (void**)&pLogger) != 0)
	{
		/* Memory allocation failed */
		return BRSE_ARL_OUT_OF_MEMORY;
	}
	/* Put valid information into the logger structure */
	memset((void*)pLogger, 0, LoggerTypSize);

	/* Store some information */
	pLogger->ID = BRSE_ARL_ID_BASE | (unsigned long)ID;
	pLogger->LoggerTypSize = LoggerTypSize;

	strncpy(pLogger->LogbookName, Name, sizeof(pLogger->LogbookName));
	pLogger->LogbookSize = LogbookSize;
	pLogger->MaxMessageSize = MessageSize;
	pLogger->EntrySize = EntrySize;
	pLogger->MaxBufEntries = BufferedEntries;
		
		
	/* Save the new logger */
	BRSE_ARL_LoggerList[ID] = pLogger;

	return ERR_OK;
}

/*! \interface BRSE_ARL_Free
	\brief Deallocates the FIFO buffer
	
	This function writes all pending entries to the logbook and closes down the buffer.
	NOTE: Not to be called in the cyclic part of a task!
	
	\param ID Logger ID of the logbook to be written to
    \return \c 0 Function call successful
*/
unsigned short BRSE_ARL_Free(unsigned short ID)
{
	/* Check if ID is valid */
	if ((ID >= BRSE_ARL_MAX_LOGGERS) 
		|| (BRSE_ARL_LoggerList[ID] == NULL)
		|| (BRSE_ARL_LoggerList[ID]->ID != (BRSE_ARL_ID_BASE | (unsigned long)ID)))
	{
		return BRSE_ARL_ID_NOT_VALID;
	}
	
	/* Flush pending writes */
	while (BRSE_ARL_Cyclic(ID) == 65535);
	
	/* Release allocated memory */
	TMP_free(BRSE_ARL_LoggerList[ID]->LoggerTypSize, (void*)BRSE_ARL_LoggerList[ID]);
	BRSE_ARL_LoggerList[ID] = NULL;
	
	return ERR_OK;
}
