/*! \file brse_arl_cyclic.c */

#include "brse_arl_main.h"

/*! \interface BRSE_ARL_Cyclic
	\brief Cyclic call to flush pending entries to the logbook
	
	This function writes pending entries to the logbook and has to be called cyclically.
	
	\param ID Logger ID of the logbook to be written to
    \retval 0 all messages written to logger
	\retval 65535 pending entries to be written
	\retval Error Error code from the ArEventLog library
*/



long BRSE_ARL_Cyclic(unsigned short ID)
{
	BRSE_ARL_Logger_typ* pLogger = NULL;
	BRSE_ARL_LogbookEntry_typ* pCurEntry = NULL;
	DINT status = ERR_FUB_BUSY;
	
	
	/* Check if ID is valid */
	if ((ID >= BRSE_ARL_MAX_LOGGERS) 
		|| (BRSE_ARL_LoggerList[ID] == NULL)
		|| (BRSE_ARL_LoggerList[ID]->ID != (BRSE_ARL_ID_BASE | (unsigned long)ID)))
	{
		return BRSE_ARL_ID_NOT_VALID;
	}

	/* Access the chosen logger */
	pLogger = BRSE_ARL_LoggerList[ID];

	switch (pLogger->Cyclic_Step)
	{
		/* Initialize */
		case 0:

			pLogger->Cyclic_Step = 1;
						
		/* GET LOGBOOK */
		case 1:
			/* Check if a logbook with the given name is existing */
			pLogger->FB_ArEventLogGetIdent.Execute = TRUE;
			strcpy(pLogger->FB_ArEventLogGetIdent.Name, pLogger->LogbookName);
			
			ArEventLogGetIdent(&pLogger->FB_ArEventLogGetIdent);

			if(pLogger->FB_ArEventLogGetIdent.Done)
			{
				/* Save the ident of the exisiting logbook */
				pLogger->LogbookIdent = pLogger->FB_ArEventLogGetIdent.Ident;
					
				/* Go to operating state */
				pLogger->Cyclic_Step = 10;
				status = ERR_FUB_BUSY;			
			}
			else if(pLogger->FB_ArEventLogGetIdent.Error)
			{
				if(pLogger->FB_ArEventLogGetIdent.StatusID == arEVENTLOG_ERR_LOGBOOK_NOT_FOUND)
				{
					pLogger->Cyclic_Step = 2;
					status = ERR_FUB_BUSY;			
				}
				else
				{
					status = pLogger->FB_ArEventLogGetIdent.StatusID;
				}
			}
			else
			{
				status = ERR_FUB_BUSY;
			}
			
			break;
			
			
		/* CREATE LOGBOOK */
		case 2:
			/* Create a new logbook in USRROM */
			pLogger->FB_ArEventLogCreate.Execute = TRUE;
			strcpy(pLogger->FB_ArEventLogCreate.Name, pLogger->LogbookName);
			pLogger->FB_ArEventLogCreate.Size = pLogger->LogbookSize;
			pLogger->FB_ArEventLogCreate.Persistence = arEVENTLOG_PERSISTENCE_PERSIST;
			
			ArEventLogCreate(&pLogger->FB_ArEventLogCreate);
			
			if(pLogger->FB_ArEventLogCreate.Done)
			{
				pLogger->LogbookIdent = pLogger->FB_ArEventLogCreate.Ident;
					
				/* Go to operating state */
				pLogger->Cyclic_Step = 10;
				status = ERR_FUB_BUSY;			
			}
			else if(pLogger->FB_ArEventLogCreate.Busy)
			{
				status = ERR_FUB_BUSY;			
			}
			else if(pLogger->FB_ArEventLogCreate.Error)
			{
				status = pLogger->FB_ArEventLogCreate.StatusID;			
			}
		
			break;
			
		/* POP ENTRY FROM THE FIFO AND WRITE IT TO THE LOGBOOK */
		case 10:
			status = ERR_FUB_BUSY;
			if ( (pLogger->CurBufEntries == 0) )
			{	
				/* No entry in the fifo */
				/* Answer with OK then... */
				status = ERR_OK;
			}
			else if (!pLogger->fifo_write_lock)
			{
				if ( (pLogger->CurBufEntries >= pLogger->MaxBufEntries) )
				{	
					/*Lock the buffer directly to avoid loosing data*/
					pLogger->fifo_reset = 1;
					
					/*State change, prepare to reset buffer*/
					pLogger->Cyclic_Step = 14;
					
					status = ERR_FUB_BUSY;
										
				}
				else
				{
					/* Got an entry in the fifo */
					pCurEntry = (BRSE_ARL_LogbookEntry_typ*)((void*)pLogger->Buffer + pLogger->EntrySize * pLogger->ReadIndex);
						
					pLogger->FB_ArEventLogWrite.Execute = TRUE;
					pLogger->FB_ArEventLogWrite.Ident = pLogger->LogbookIdent;		
					pLogger->FB_ArEventLogWrite.EventID = pCurEntry->ErrorNo;
					pLogger->FB_ArEventLogWrite.AddDataSize = strlen(pCurEntry->ErrorMsg) + 1;
					pLogger->FB_ArEventLogWrite.AddDataFormat = arEVENTLOG_ADDFORMAT_TEXT;
					pLogger->FB_ArEventLogWrite.AddData = (UDINT)pCurEntry->ErrorMsg;
					strcpy(pLogger->FB_ArEventLogWrite.ObjectID, pCurEntry->User);
					
					if(pLogger->FB_ArEventLogWrite.Done)
					{
						pLogger->FB_ArEventLogWrite.Execute = FALSE;
					}
					
					ArEventLogWrite(&pLogger->FB_ArEventLogWrite);
						
					if(pLogger->FB_ArEventLogWrite.Done)
					{
						pLogger->ReadIndex++;
						if (pLogger->ReadIndex >= pLogger->MaxBufEntries)
						{
							pLogger->ReadIndex = 0;
						}
									
						pLogger->CurBufEntries--;
									
						/* Return OK if no more entries shall be written */
						status = (pLogger->CurBufEntries == 0) ? ERR_OK : ERR_FUB_BUSY;				
					}
					else if(pLogger->FB_ArEventLogWrite.Error)
					{
						status = pLogger->FB_ArEventLogWrite.StatusID;
					}
					else
					{
						status = ERR_FUB_BUSY;
					}
				}
			}
			else
			{
				/* Write is active */
				status = ERR_FUB_BUSY;
			}
			break;
		case 14:
			status = ERR_FUB_BUSY;
						
			if (pLogger->FB_ArEventLogWrite.StatusID == ERR_FUB_BUSY )
			{
				/*Wait if a line is being written to the logg book.*/
				ArEventLogWrite(&pLogger->FB_ArEventLogWrite);	
					
			}
			else
			{
			
				/*Switch state, empty buffer.*/
				pLogger->Cyclic_Step = 15;
			}
			
					
			break;
					
		case 15: /*Output reset start message*/
				status = ERR_FUB_BUSY;
				
				pLogger->FB_ArEventLogWrite.Execute 		= TRUE;
				pLogger->FB_ArEventLogWrite.Ident 			= pLogger->LogbookIdent;
				pLogger->FB_ArEventLogWrite.EventID 		= -536820909; /* Severity = Error, Code = 50003 */
				strcpy(pLogger->tempString, "BUFFER RESET STARTED");
				pLogger->FB_ArEventLogWrite.AddData			= (UDINT)(pLogger->tempString);
				pLogger->FB_ArEventLogWrite.AddDataSize 	= strlen(pLogger->tempString) + 1;
				pLogger->FB_ArEventLogWrite.AddDataFormat 	= arEVENTLOG_ADDFORMAT_TEXT;					
	
				ArEventLogWrite(&pLogger->FB_ArEventLogWrite);
									
				if (pLogger->FB_ArEventLogWrite.StatusID == ERR_OK )
				{
					/*Switch state, empty buffer.*/
					pLogger->Cyclic_Step = 20;
					
				}
			break;	
		
		
		case 20: /*Empty the buffer, reset.*/
			status = ERR_FUB_BUSY;	
			if ( (pLogger->CurBufEntries == 0) )
			{	
				/*Buffer reset completed, switcht to state where message is output.*/
				pLogger->Cyclic_Step = 21;					
										
			}
			else
			{
				/*Empty buffer*/
				/* Got an entry in the fifo */
				pCurEntry = (BRSE_ARL_LogbookEntry_typ*)((UDINT)pLogger->Buffer + pLogger->EntrySize * pLogger->ReadIndex);
			
				pLogger->FB_ArEventLogWrite.Execute 		= TRUE;
				pLogger->FB_ArEventLogWrite.Ident 			= pLogger->LogbookIdent;
				pLogger->FB_ArEventLogWrite.EventID 		= pCurEntry->ErrorNo;
				//TODO: Event ID log level 
				pLogger->FB_ArEventLogWrite.AddDataFormat 	= arEVENTLOG_ADDFORMAT_TEXT;
				pLogger->FB_ArEventLogWrite.AddData 		= (UDINT)pCurEntry->ErrorMsg;
				strcpy(pLogger->FB_ArEventLogWrite.ObjectID, pCurEntry->User);
				//					pLogger->FB_AsArLogWrite.mem = (UDINT)NULL;
				//					pLogger->FB_AsArLogWrite.len = 0;
				
				ArEventLogWrite(&pLogger->FB_ArEventLogWrite);					
				
				if(pLogger->FB_ArEventLogWrite.Done)
				{
					pLogger->ReadIndex++;
					if (pLogger->ReadIndex >= pLogger->MaxBufEntries)
					{
						pLogger->ReadIndex = 0;
					}
					
					pLogger->CurBufEntries--;
					
					/* Return OK if no more entries shall be written */
					status = (pLogger->CurBufEntries == 0) ? ERR_OK : ERR_FUB_BUSY;				
				}
				else if(pLogger->FB_ArEventLogWrite.Error)
				{
					status = pLogger->FB_ArEventLogWrite.StatusID;
				}
				else
				{
					status = ERR_FUB_BUSY;
				}
			}
			break;
			
		case 21: /*Output message the reset is completed*/
				status = ERR_FUB_BUSY; 
				
				pLogger->FB_ArEventLogWrite.Execute 		= TRUE;
				pLogger->FB_ArEventLogWrite.Ident 			= pLogger->LogbookIdent;
				pLogger->FB_ArEventLogWrite.EventID			= -536820908;
				pLogger->FB_ArEventLogWrite.AddDataFormat 	= arEVENTLOG_ADDFORMAT_TEXT;
				strcpy(pLogger->tempString, "BUFER RESET COMPLETED");
				pLogger->FB_ArEventLogWrite.AddData 		= (UDINT)pLogger->tempString;
				pLogger->FB_ArEventLogWrite.AddDataSize 	= strlen(pLogger->tempString) + 1;
	
				ArEventLogWrite(&pLogger->FB_ArEventLogWrite);
			
				status = ERR_FUB_BUSY; 					
				if (pLogger->FB_ArEventLogWrite.StatusID == ERR_OK )
				{
					status = ERR_OK;
					pLogger->fifo_reset = 0;
					pLogger->Cyclic_Step = 10;
						
				}
			
			
			break;
	
	}
	
	return status;
}
