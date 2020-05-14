
FUNCTION BRSE_ARL_Alloc : UINT (*Allocates the FIFO buffer for the logger*)
	VAR_INPUT
		ID : UINT; (*Logger ID of the logbook to be written to*)
		Name : STRING[25]; (*Name of the logbook to which to write to.*)
		LogbookSize : UDINT; (*Size of the logbook in bytes (if a new one has to be created).*)
		MessageSize : UDINT; (*Maximum length of a single message string for the logbook*)
		BufferedEntries : UDINT; (*Maximum number of messages that can be stored in the FIFO buffer*)
	END_VAR
END_FUNCTION
(*	VAR_INPUT
		ID : UINT; (*Logger ID of the logbook to be written to*)
(*		ErrorNumber : UDINT; (*Error number to show up in the logbook*)
(*FUNCTION BRSE_ARL_Info : UINT (*Writes an info message to the logbook*)
(*		ErrorMessage : STRING[32767]; (*Error message in the logbook*)
(*		pMsgData : UDINT; (*Address of a BRSE_ARL_Arguments_typ structure that contains data values*)
(*	END_VAR
END_FUNCTION--*/ *)

FUNCTION BRSE_ARL_Cyclic : DINT (*Cyclic call to flush pending entries to the logbook*)
	VAR_INPUT
		ID : UINT; (*Logger ID of the logbook to be written to*)
	END_VAR
END_FUNCTION

FUNCTION_BLOCK BRSE_ARL_DebugInfo
	VAR_INPUT
		ID : UINT;
	END_VAR
	VAR_OUTPUT
		Info : BRSE_ARL_Logger_typ;
		Status : UINT;
	END_VAR
END_FUNCTION_BLOCK
(*FUNCTION BRSE_ARL_Fatal : UINT (*Writes a fatal message to the logbook*)
(*	VAR_INPUT
				ID : UINT; (*Logger ID of the logbook to be written to*)
(*		ErrorNumber : UDINT; (*Error number to show up in the logbook*)
(*		ErrorMessage : STRING[32767]; (*Error message in the logbook*)
(*		pMsgData : UDINT; (*Address of a BRSE_ARL_Arguments_typ structure that contains data values*)
(*	END_VAR
(*END_FUNCTION *)

FUNCTION BRSE_ARL_Free : UINT (*Deallocates the FIFO buffer *)
	VAR_INPUT
		ID : UINT; (*Logger ID of the logbook to be written to*)
	END_VAR
END_FUNCTION
(*FUNCTION BRSE_ARL_Warning : UINT (*Writes a warning message to the logbook*)
(*	VAR_INPUT
		ID : UINT; (*Logger ID of the logbook to be written to*)
(*		ErrorNumber : UDINT; (*Error number to show up in the logbook*)
(*		ErrorMessage : STRING[32767]; (*Error message in the logbook*)
(*		pMsgData : UDINT; (*Address of a BRSE_ARL_Arguments_typ structure that contains data values*)
(*	END_VAR
(*END_FUNCTION*)

FUNCTION BRSE_ARL_Log : UINT
	VAR_INPUT
		ID : UINT;
		ErrorNumber : UDINT;
		User : STRING[32];
		ErrorMessage : STRING[32767];
	END_VAR
END_FUNCTION
