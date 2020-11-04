(*******************************************************************************
 * Copyright: B&R Industrial Automation
 * Author:    Tyler Matijevich
 * Created:   September 27, 2020/11:19 
********************************************************************************
 * Description: Example program for formatting string in IEC code and logging 
 user entries in the logger
********************************************************************************)

PROGRAM _INIT
	
	// Initialize REAL and DINT variables
	VarDint 	:= 45678; // A value bigger than an INT
	VarReal 	:= 3.141592653589; // 32 bit floating value with more than enough significant digits
	
	MessageArguments.b[0] := TRUE;
	MessageArguments.r[0] := 78.768;
	MessageArguments.i[0] := -2144327918; // Example: ArEventLog error ID
	MessageArguments.s[0] := 'INIT';
	
END_PROGRAM

PROGRAM _CYCLIC

	// Test DINT and REAL to STRING conversions
	ReturnDint := brsitoa(VarDint, ADR(sDint));
	ReturnReal := brsftoa(VarReal, ADR(sReal));

	sConstructMessage := 'Sequence completed is %b, Temp is %r deg F, Error code %i, State %s';
	IecFormatString(ADR(sFormattedMessage), SIZEOF(sFormattedMessage), ADR(sConstructMessage), ADR(MessageArguments));
	
END_PROGRAM

PROGRAM _EXIT

END_PROGRAM
