
PROGRAM _INIT
	
	FormatValues.b[0] := TRUE;
	FormatValues.f[0] := 12.34;
	FormatValues.i[0] := 33;
	FormatValues.s[0] := 'All Clear';
	
END_PROGRAM

PROGRAM _CYCLIC
	
	IecStringCopy(Destination, 
		SIZEOF(Destination),
		Source);
		
	ReferenceString1 ACCESS ADR(Raw1);
	ReferenceString2 ACCESS ADR(Raw2);
	IecStringCopy(ReferenceString1, SIZEOF(ReferenceString1), ReferenceString2);
	
	IecStringFormat(FromattedString, 
		SIZEOF(FromattedString), 
		'Error: %b, Temp: %f C, Step: %i, Message: %s',
		FormatValues);
					
	IecStringInteger(PaddedInteger, 
		SIZEOF(PaddedInteger), 
		MyInteger, 
		6, 
		FALSE);
		
	GetDateTime(enable := TRUE, pDTStructure := ADR(CurrentDateTime));
	IecStringDateTime(DateTimeString, SIZEOF(DateTimeString), FormatDateTime, DateTime);
	
END_PROGRAM
