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
	
	times[1] := 0.0;
	times[2] := 0.25;
	times[3] := 0.4;
	times[4] := 0.5;
	times[5] := 0.6;
	
	velocities[1] := 0.0;
	velocities[2] := 1.9;
	velocities[3] := 0.75;
	velocities[4] := 0.75;
	velocities[5] := 1.2;

END_PROGRAM

PROGRAM _CYCLIC
	
	status_GetAcc := Kin_GetAcc(dt, dx, v0, vf, vmin, vmax, AccSoln);
	
	status_GetAccInTimespanPlus := Kin_GetAccInTimespanPlus(dt, dx, v0, vf, vmin, vmax, AccInTimespanPlusSoln);
	
	TimespanValid := Kin_GetTimespan(dx - EXPT(v0, 2) / (2.0 * AccInTimespanPlusSoln.a), v0, vf, vmin, vmax, AccInTimespanPlusSoln.a, TimespanSoln);
	
	VelProfPointResult := Kin_GetVelProfPoint(0.0, times, velocities, 5, 0.515, VelProfPointSoln);
	
END_PROGRAM

PROGRAM _EXIT
	
END_PROGRAM
