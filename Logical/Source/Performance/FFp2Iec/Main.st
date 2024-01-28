
(* 100 calls to convert float to string *)
PROGRAM _CYCLIC
	FOR i := 0 TO 99 DO
		a := REAL_TO_STRING(123.456e-23);
	END_FOR
END_PROGRAM
