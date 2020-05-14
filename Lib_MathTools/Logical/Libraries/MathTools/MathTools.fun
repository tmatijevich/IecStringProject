(*Integer wrap*)

FUNCTION Math_WrapUSINT : USINT
	VAR_INPUT
		Value : DINT;
		LowerBound : DINT;
		UpperBound : DINT;
	END_VAR
END_FUNCTION

FUNCTION Math_WrapSINT : SINT
	VAR_INPUT
		Value : DINT;
		LowerBound : DINT;
		UpperBound : DINT;
	END_VAR
END_FUNCTION

FUNCTION Math_WrapUINT : UINT
	VAR_INPUT
		Value : DINT;
		LowerBound : DINT;
		UpperBound : DINT;
	END_VAR
END_FUNCTION

FUNCTION Math_WrapINT : INT
	VAR_INPUT
		Value : DINT;
		LowerBound : DINT;
		UpperBound : DINT;
	END_VAR
END_FUNCTION
(*Floating point wrap*)

FUNCTION Math_WrapREAL : REAL
	VAR_INPUT
		Value : LREAL;
		LowerBound : LREAL;
		UpperBound : LREAL;
	END_VAR
END_FUNCTION

FUNCTION Math_WrapLREAL : LREAL
	VAR_INPUT
		Value : LREAL;
		LowerBound : LREAL;
		UpperBound : LREAL;
	END_VAR
END_FUNCTION
(*Quadtratic equation*)

FUNCTION Math_2ndOrderRoots : BOOL
	VAR_INPUT
		p2 : LREAL;
		p1 : LREAL;
		p0 : LREAL;
	END_VAR
	VAR_IN_OUT
		Solution : Math2ndOrderRootsSoln_typ;
	END_VAR
END_FUNCTION
