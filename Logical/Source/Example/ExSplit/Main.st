
PROGRAM _INIT
	
	Source := 'The quick brown fox jumps over the lazy dog';
	Delimeters := ' ';
	
END_PROGRAM

PROGRAM _CYCLIC
	
	IF Run THEN
		Run := FALSE;
		
		brsmemset(ADR(Words), 0, SIZEOF(Words));
		Index := 0;
		
		SourceReference ACCESS ADR(Source);
		REPEAT
			IecStringSplit(Words[Index], SIZEOF(Words[Index]), SourceReference, Delimeters, NextAddress);
			IF NextAddress <> 0 THEN
				SourceReference ACCESS NextAddress;
			END_IF
			Index := Index + 1;
		UNTIL
			Index >= SIZEOF(Words) / SIZEOF(Words[0]) OR NextAddress = 0
		END_REPEAT
	END_IF
	
END_PROGRAM
