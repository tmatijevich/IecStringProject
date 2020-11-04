
TYPE
	BRSE_ARL_Arguments_typ : 	STRUCT 
		r : ARRAY[0..4]OF REAL;
		s : ARRAY[0..4]OF UDINT;
		b : ARRAY[0..4]OF BOOL;
		i : ARRAY[0..4]OF DINT;
	END_STRUCT;
	BRSE_ARL_Logger_typ : 	STRUCT  (* ID CHECK *)
		ID : UDINT; (*unsigned long ID;*) (*Size of the structure*)
		LoggerTypSize : DINT; (*long LoggerTypSize;*) (*VARIABLES*)
		LogbookIdent : UDINT; (*UDINT LogbookIdent;*)
		LogbookSize : UDINT; (*UDINT LogbookSize;*) (*Size of the logbook*)
		LogbookName : STRING[26]; (*char LogbookName[26];*) (*Name of the logbook (max. 25 chars)*)
		MaxMessageSize : UDINT; (*unsigned int MaxMessageSize;*) (*Max. size of a text message*)
		Cyclic_Step : UDINT; (*unsigned int Cyclic_Step;*) (* FUNCTION BLOCKS *)
		FB_ArEventLogGetIdent : ArEventLogGetIdent; (*AsArLogGetInfo_typ FB_AsArLogGetInfo;*)
		FB_ArEventLogCreate : ArEventLogCreate; (*AsArLogCreate_typ  FB_AsArLogCreate;*)
		FB_ArEventLogWrite : ArEventLogWrite; (*AsArLogWrite_typ   FB_AsArLogWrite;*) (*FIFO BUFFER*)
		fifo_write_lock : BOOL; (*Locks critical sections in the FIFO write processing*)
		fifo_reset : BOOL; (*Clearing FIFO memory, used if FIFO full when trying to read.*)
		tempString : STRING[50];
		EntrySize : UDINT; (* Size of a single logbook entry *)
		MaxBufEntries : UDINT; (*Max. number of buffered entries*)
		CurBufEntries : UDINT; (*Number of entries in the buffer*)
		ReadIndex : UDINT; (*Current index from which to read*)
		WriteIndex : UDINT; (* Current index at which to write *)
		Buffer : ARRAY[0..0]OF BRSE_ARL_LogbookEntry_typ; (*Buffer start position (must be last in the struct)*)
	END_STRUCT;
	BRSE_ARL_LogbookEntry_typ : 	STRUCT 
		User : STRING[36];
		ErrorNo : UDINT;
		ErrorMsg : STRING[0]; (* Only buffer start position, size depends on the requested size in Alloc *)
	END_STRUCT;
END_TYPE
