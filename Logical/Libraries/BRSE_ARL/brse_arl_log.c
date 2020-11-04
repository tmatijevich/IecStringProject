/*! \file brse_arl_log.c */

#include "brse_arl_main.h"

/* Internal function to concat the string */
//static void CreateErrorMessage(char* dst, long dst_size, char* src, BRSE_ARL_Arguments_typ* pArguments)
//{
//	/* Temporary array for string concatenations */
//	char temp_string[16];
//
//	/* Size of a string that is concatenated to the destination */
//	int concat_string_size;
//	
//	/* Array index counters */
//	int bool_counter   = 0;		
//	int int_counter    = 0;
//	int real_counter   = 0;
//	int string_counter = 0;
//
//	/* Run through the source message and copy it to the destination until src is empty or destination is full */
//	while ((*src != '\0') && (dst_size > 0))
//	{
//		/* Special character found and MessageData given */
//		if ((pArguments != NULL) && (*src == '%'))
//		{
//			/* Temporary 'close' the destination string (to allow strcat...) */
//			*dst = '\0';
//		
//			/* Consume the char and investigate the command */
//			switch (*(++src))
//			{
//				/* Insert bool */
//				case 'b':
//					/* Only take a value if an array entry exists */
//					if (bool_counter < ARRAY_ENTRIES(pArguments->b))
//					{
//						if (pArguments->b[bool_counter])
//						{
//							strncat(dst, "TRUE", dst_size);
//							concat_string_size = MIN(dst_size, 4);
//						}
//						else
//						{
//							strncat(dst, "FALSE", dst_size);
//							concat_string_size = MIN(dst_size, 5);
//						}
//						bool_counter++;
//						dst += concat_string_size;
//						dst_size -= concat_string_size;
//					}
//					src++;
//					break;
//					
//				/* Insert integer */
//				case 'i':
//					/* Only take a value if an array entry exists */
//					if (int_counter < ARRAY_ENTRIES(pArguments->i))
//					{
//						concat_string_size = brsitoa(pArguments->i[int_counter], (UDINT)temp_string);
//						concat_string_size = MIN(dst_size, concat_string_size);
//						strncat(dst, temp_string, dst_size);
//						int_counter++;
//						dst += concat_string_size;
//						dst_size -= concat_string_size;
//					}
//					src++;
//					break;
//					
//				/* Insert real */
//				case 'r':
//					/* Only take a value if an array entry exists */
//					if (real_counter < ARRAY_ENTRIES(pArguments->r))
//					{
//						concat_string_size = brsftoa(pArguments->r[real_counter], (UDINT)temp_string);
//						concat_string_size = MIN(dst_size, concat_string_size);
//						strncat(dst, temp_string, dst_size);
//						real_counter++;
//						dst += concat_string_size;
//						dst_size -= concat_string_size;
//					}
//					src++;
//					break;
//					
//				/* Insert string */
//				case 's':
//					/* Only take a value if an array entry exists */
//					if (string_counter < ARRAY_ENTRIES(pArguments->s))
//					{
//						if (pArguments->s[string_counter]) 
//						{
//							strncat(dst, (char*)pArguments->s[string_counter], dst_size);
//							concat_string_size = MIN(dst_size, strlen((char*)pArguments->s[string_counter]));
//							dst += concat_string_size;
//							dst_size -= concat_string_size;
//						}
//						string_counter++;
//					}
//					src++;
//					break;
//					
//				/* Insert percent */
//				case '%':
//					*dst++ = '%';
//					src++;
//					dst_size--;
//					break;
//					
//				/* ELSE */
//				default:
//					/* Ignore the character */
//					src++;
//					break;
//			}
//		}
//		else
//		{
//			*dst++ = *src++;
//			dst_size--;
//		}
//	}
//	
//	/* Add the end of string */
//	*dst = '\0';
//} 
/*! \interface BRSE_ARL_Log
	\brief Writes a message to the logbook

	This function writes a message to the buffered logbook using the given
	ErrorNumber and ErrorMessage. If you add your own error number be sure that the customer bit is set.
	USE 32-bit event ID to make error numbers - ArEventLogMakeEventID()
	
	If the address of a BRSE_ARL_Arguments_typ structure is passed,
	its variables can be referenced in the ErrorMessage string by %[b|i|r|s]. Each usage
	of a wildcard consumes the according variable and moves on the next one within the array.

	E.g: 
	MessageString = "Digital input %s: %b, analogue input %s: %i" 
	BRSE_ARL_Arguments_typ = { s[0] = "Valve 1"; s[1] = "Encoder 2"; b[0] = 'TRUE'; i[0] = 4388 }
	
	Will create a logbook entry:
	"Digital input Valve 1: TRUE, analogue input Encoder 2: 4388"
	
	@ref Examples

	\param ID Logger ID of the logbook to be written to
    \param ErrorNumber Error number to show up in the logbook
    \param User Created by to show up in the logbook
    \param ErrorMessage Error message in the logbook
    \param pArguments Address of a BRSE_ARL_Arguments_typ structure that contains data values
    \retval 0 Function call successful
*/
unsigned short BRSE_ARL_Log(unsigned short ID,unsigned long ErrorNumber,plcstring* User, plcstring* ErrorMessage)
{
	BRSE_ARL_Logger_typ* pLogger;
	BRSE_ARL_LogbookEntry_typ* pCurEntry;
	UINT status;

	/* Check the ID */
	if ((ID >= BRSE_ARL_MAX_LOGGERS) 
		|| (BRSE_ARL_LoggerList[ID] == NULL)
		|| (BRSE_ARL_LoggerList[ID]->ID != (BRSE_ARL_ID_BASE | (unsigned long)ID)))
	{
		return BRSE_ARL_ID_NOT_VALID;
	}

	/* Access the chosen logger */
	pLogger = BRSE_ARL_LoggerList[ID];
	
	/* Check and set the semaphore */
	if (!pLogger->fifo_write_lock && !pLogger->fifo_reset)
	{
		pLogger->fifo_write_lock = TRUE;
		
		/* Create the logbook message and put it into the buffer */
		pCurEntry = (BRSE_ARL_LogbookEntry_typ*)((UDINT)pLogger->Buffer + pLogger->EntrySize * pLogger->WriteIndex);
	
		strcpy(pCurEntry->User, User);
		pCurEntry->ErrorNo = ErrorNumber;
		strcpy(pCurEntry->ErrorMsg, ErrorMessage); /* Copy the error message string as is */
		
		/* Do not format the error message here any more */
		//CreateErrorMessage(pCurEntry->ErrorMsg, (long)pLogger->MaxMessageSize, ErrorMessage,(BRSE_ARL_Arguments_typ*)pArguments);
	
		/* Adjust the FIFO:
	     * Increase the WriteIndex, but reset it to 0 if MaxBufEntries have been exceeded
		 */
		pLogger->WriteIndex++;
		if (pLogger->WriteIndex >= pLogger->MaxBufEntries)
		{
			pLogger->WriteIndex = 0;
		}
	
		/* Check if space is available in the buffer */
		if (pLogger->CurBufEntries >= pLogger->MaxBufEntries)
		{
			/*buffer is full, shift the read position (delete the oldest entry)*/
			pLogger->ReadIndex++;
			if (pLogger->ReadIndex >= pLogger->MaxBufEntries)
			{
				pLogger->ReadIndex = 0;
			}
		}
		else
		{
			/*buffer is not yet full, increase the buffer size*/
			pLogger->CurBufEntries++;
		}
		
		pLogger->fifo_write_lock = FALSE;
		status = ERR_OK;	
	}
	else
	{
		status = ERR_FUB_BUSY;
	}
	
	return status;
}

/*! \interface BRSE_ARL_Info
	\brief Writes an info message to the logbook

	This function writes an info message to the buffered logbook using the given
	ErrorNumber and ErrorMessage. If you add your own error number be sure to only 
	use values > 50000, lower values are reserved for AS.
	
	If the address of a BRSE_ARL_Arguments_typ structure is passed,
	its variables can be referenced in the ErrorMessage string by %[b|i|r|s]. Each usage
	of a wildcard consumes the according variable and moves on to the next one within the array.

	E.g: 
	MessageString = "Digital input %s: %b, analogue input %s: %i" 
	BRSE_ARL_Arguments_typ = { s[0] = "Valve 1"; s[1] = "Encoder 2"; b[0] = 'TRUE'; i[0] = 4388 }
	
	Will create a logbook entry:
	"Digital input Valve 1: TRUE, analogue input Encoder 2: 4388"
	
	@ref Examples

	\param ID Logger ID of the logbook to be written to
    \param ErrorNumber Error number to show up in the logbook
    \param ErrorMessage Error message in the logbook
    \param pArguments Address of a BRSE_ARL_Arguments_typ structure that contains data values
    \retval 0 Function call successful
*/
//unsigned short BRSE_ARL_Info(unsigned short ID, unsigned long ErrorNumber, plcstring* ErrorMessage, unsigned long pArguments)
//{
//	return BRSE_ARL_Log(ID, 1, ErrorNumber, ErrorMessage, (BRSE_ARL_Arguments_typ*)pArguments);
//}

/*! \interface BRSE_ARL_Warning
	\brief Writes a warning message to the logbook

	This function writes a warning message to the buffered logbook using the given
	ErrorNumber and ErrorMessage. If you add your own error number be sure to only 
	use values > 50000, lower values are reserved for AS.
	
	If the address of a BRSE_ARL_Arguments_typ structure is passed,
	its variables can be referenced in the ErrorMessage string by %[b|i|r|s]. Each usage
	of a wildcard consumes the according variable and moves on the next one within the array.

	E.g: 
	MessageString = "Digital input %s: %b, analogue input %s: %i" 
	BRSE_ARL_Arguments_typ = { s[0] = "Valve 1"; s[1] = "Encoder 2"; b[0] = 'TRUE'; i[0] = 4388 }
	
	Will create a logbook entry:
	"Digital input Valve 1: TRUE, analogue input Encoder 2: 4388"
	
	@ref Examples

	\param ID Logger ID of the logbook to be written to
    \param ErrorNumber Error number to show up in the logbook
    \param ErrorMessage Error message in the logbook
    \param pArguments Address of a BRSE_ARL_Arguments_typ structure that contains data values
    \retval 0 Function call successful
*/
//unsigned short BRSE_ARL_Warning(unsigned short ID, unsigned long ErrorNumber, plcstring* ErrorMessage, unsigned long pArguments)
//{
//	return BRSE_ARL_Log(ID, 2, ErrorNumber, ErrorMessage, (BRSE_ARL_Arguments_typ*)pArguments);
//}

/*! \interface BRSE_ARL_Fatal
	\brief Writes a fatal message to the logbook

	This function writes a fatal message to the buffered logbook using the given
	ErrorNumber and ErrorMessage. If you add your own error number be sure to only 
	use values > 50000, lower values are reserved for AS.
	
	If the address of a BRSE_ARL_Arguments_typ structure is passed,
	its variables can be referenced in the ErrorMessage string by %[b|i|r|s], see examples.c

	E.g: 
	MessageString = "Digital input %s: %b, analogue input %s: %i" 
	BRSE_ARL_Arguments_typ = { s[0] = "Valve 1"; s[1] = "Encoder 2"; b[0] = 'TRUE'; i[0] = 4388 }
	
	Will create a logbook entry:
	"Digital input Valve 1: TRUE, analogue input Encoder 2: 4388"
	
	@ref Examples

	\param ID Logger ID of the logbook to be written to
    \param ErrorNumber Error number to show up in the logbook
    \param ErrorMessage Error message in the logbook
    \param pArguments Address of a BRSE_ARL_Arguments_typ structure that contains data values
    \retval 0 Function call successful
*/
//unsigned short BRSE_ARL_Fatal(unsigned short ID, unsigned long ErrorNumber, plcstring* ErrorMessage, unsigned long pArguments)
//{
//	return BRSE_ARL_Log(ID, 3, ErrorNumber, ErrorMessage, (BRSE_ARL_Arguments_typ*)pArguments);
//}
