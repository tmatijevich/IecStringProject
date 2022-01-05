(*******************************************************************************
 * File       Sample\Main.st
 * Author:    Tyler Matijevich
 * Created:   September 27, 2020/11:19 
********************************************************************************
 * Description: Example program for formatting string in IEC code and logging 
 user entries in the logger
********************************************************************************)

PROGRAM _INIT
	
	// Initialize REAL and DINT variables
	VarDint 	:= 45678; // Try -2147483648
	VarReal 	:= 3.141592653589; // 32 bit floating value with more than enough significant digits, try -12345600000.0
	
	Size := SIZEOF(Message);
	
	// Runtime values
	FormatArgs.b[0] := FALSE; // BOOL
	FormatArgs.r[0] := 78.768; // LREAL
	FormatArgs.i[0] := -2144327918; // DINT, e.g. Status ID
	FormatArgs.s[0] := 'INIT'; // STRING
	
	Format := 'Status %b, Temp %r F, Code %i, State %s';
	
END_PROGRAM

PROGRAM _CYCLIC

	// Test DINT and REAL to STRING conversions
	ReturnDint := brsitoa(VarDint, ADR(sDint));
	ReturnReal := brsftoa(VarReal, ADR(sReal));

	// The watch window will only print out 85 characters
	Length := IecFormatString(Message, Size, Format, FormatArgs);
									 
END_PROGRAM

PROGRAM _EXIT

END_PROGRAM
