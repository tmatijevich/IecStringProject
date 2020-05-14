(*******************************************************************************
 * Copyright: B&R Industrial Automation
 * Author:    Tyler Matijevich
 * Created:   May 14, 2020/11:24 AM 
********************************************************************************
 * Description: Example program for MathTools user library 
********************************************************************************)

PROGRAM _INIT
	
	In1 := 5;
	In2 := 1;
	In3 := 1200;
	In4 := -1400;
	In5 := 734.0;
	In6 := -12.0;
	
	p2 := 2.0;
	p1 := -1.0;
	p0 := -6.0;
	
	In7 := -1.0;

END_PROGRAM

PROGRAM _CYCLIC
	
	Out1 := Math_WrapUSINT(In1, 1, 4);
	Out2 := Math_WrapSINT(In2, -3, 0);
	Out3 := Math_WrapUINT(In3, 1, 1000);
	Out4 := Math_WrapINT(In4, -1200, -1);
	Out5 := Math_WrapREAL(In5, 0.0, 360.0);
	Out6 := Math_WrapLREAL(In6, 0.0, 1000.0);
	
	ValidRoots := Math_2ndOrderRoots(p2, p1, p0, SolnRoots);
	
	Out7 := Math_UnitStep(In7);
	
END_PROGRAM

PROGRAM _EXIT
	
END_PROGRAM
