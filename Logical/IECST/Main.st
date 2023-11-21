
PROGRAM _CYCLIC
	
	IecStringCopy(Destination, 
		SIZEOF(Destination),
		Source);
	
	IecStringFormat(FromattedString, 
		SIZEOF(FromattedString), 
		'Error: %b, Temp: %f C, Step: %i, Message: %s',
		FormatValues);
					
	IecStringInteger(PaddedInteger, 
		SIZEOF(PaddedInteger), 
		MyInteger, 
		6, 
		FALSE);
	
END_PROGRAM
