/*! \page Example

	\section Example
	
	This example logs events in the default user logger file. 

	\par LoggerExample.var:

\code

VAR
	cmdState : UINT;
	Args : BRSE_ARL_Arguments_typ;
	name : STRING[32];
	value : DINT;
	valueExceed : DINT;
	tempSet : REAL;
	tempMax : REAL;
	cooling : BOOL;
	age : INT;
END_VAR

\endcode

	\par LoggerExample.st:

\code

PROGRAM _INIT

	(*fetch the user logger module and interally address it as log 1*)
	BRSE_ARL_Alloc(1, '', 0, MessageSize:=100, BufferedEntries:=10);

	strcpy(ADR(name),ADR('Tom'));
	age := 30;

	value := 100;
	valueExceed := 12;
	
	tempSet := 77.3;
	tempMax := 55;
	cooling := TRUE;

END_PROGRAM

PROGRAM _CYCLIC

	CASE cmdState OF
	
		1: (* add an information message *)
			Args.i[0] := age;
			Args.s[0] := ADR(name);
			BRSE_ARL_Info(1, 50001, 'Your name is: %s and you are %i years old',ADR(Args));
			(*will result in:
			Your name is: Tom and you are 30 years old
			*)
	
		2: (*add a warning message*)
			Args.i[0] := value;
			Args.i[1] := valueExceed;
			BRSE_ARL_Warning(1, 50002, 'You have exceeded value %i by %i units',ADR(Args));
			(*will result in:
			You have exceeded value 100 by 12 units
			*)
	
		3: (*add a fatal message*)
			Args.r[0] := tempSet;
			Args.r[1] := tempMax;
			Args.b[0] := cooling;
			BRSE_ARL_Fatal(1, 50003, 'PLC fatal error. temperature is: %r, and cooling is %b, max temp is %r',ADR(Args));
			(*will result in:
			PLC fatal error. temperature is: 77.3, and cooling is TRUE, max temp is 55
			*)
	
	END_CASE
	
	cmdState := 0;
	
	(*put out the messages into the logbook*)
	BRSE_ARL_Cyclic(1);

END_PROGRAM

\endcode

The result will be the following:
	
\image html LoggerScreenUser.jpg

*/
