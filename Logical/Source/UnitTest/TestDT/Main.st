
PROGRAM _INIT
	GetDateAndTime(enable := TRUE, pDTStructure := ADR(DateAndTimeData));
END_PROGRAM

PROGRAM _CYCLIC
	IecStringDateTime(String1, SIZEOF(String1), DateAndTimeData, String2);
END_PROGRAM
