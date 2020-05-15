(*******************************************************************************
 * Copyright: B&R Industrial Automation
 * Author:    Tyler Matijevich
 * Created:   May 14, 2020/6:28 PM 
********************************************************************************
 * Description: Example program to test the PathKin library 
********************************************************************************)

PROGRAM _INIT
	
	dt := 0.300;
	dx := 0.350;
	v0 := 1.9;
	vf := 1.2;
	vmin := 0.75;
	vmax := 3.0;

END_PROGRAM

PROGRAM _CYCLIC
	
	AccValid := Kin_GetAcc(dt, dx, v0, vf, vmin, vmax, AccSoln);
	
	AccInTimespanPlusValid := Kin_GetAccInTimespanPlus(dt, dx, v0, vf, vmin, vmax, AccInTimespanPlusSoln);
	
END_PROGRAM

PROGRAM _EXIT
	
END_PROGRAM
