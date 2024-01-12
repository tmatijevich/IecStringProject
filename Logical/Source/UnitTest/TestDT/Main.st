
PROGRAM _INIT
	GetDateAndTime(enable := TRUE, pDTStructure := ADR(DateAndTimeData));
END_PROGRAM

PROGRAM _CYCLIC
	IecStringDateTime(String1, SIZEOF(String1), String2, DateAndTimeData);
END_PROGRAM
