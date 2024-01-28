
(* 100 calls to concatenate 80 characters to length of 80 *)
PROGRAM _CYCLIC
	FOR i := 0 TO 99 DO
		a := CONCAT('0123456789abcdefghij0123456789abcdefghij0123456789abcdefghij0123456789abcdefghij', '0123456789abcdefghij0123456789abcdefghij0123456789abcdefghij0123456789abcdefghij');
	END_FOR
END_PROGRAM
