%!octave

function [soln, valid] = PK_GetVel(dt, dx, v0, vf, vmin, vmax, a)
	% Determine the intermediate velocity required to perform a move
	% This function assumes positive kinematic values and infinite jerk
	% Date: 2020-08-20
	% Created by: Tyler Matijevich
	
	valid = true;
	soln.v12 = 0.0; soln.t1 = 0.0; soln.t2 = 0.0; soln.cs = 0.0; % Fallback/invalid result
	
	% phase1 - phase2
	% acc - acc - 11
	% acc - dec - 12
	% dec - acc - 21
	% dec - dec - 22
	
	% 0 - acc/dec - dxInflection1
	% acc/dec - 0 - dxInflection2
	
	dxInflection1 = abs(v0 ^ 2 - vf ^ 2) / (2.0 * a) + v0 * (dt - abs(v0 - vf) / a);
	dxInflection2 = abs(v0 ^ 2 - vf ^ 2) / (2.0 * a) + vf * (dt - abs(v0 - vf) / a);
	
	if dx > dxInflection1
		phase1 = 1.0;
	elseif dx < dxInflection1
		phase1 = -1.0;
	else
		phase1 = 0.0;
	endif
	
	if dx > dxInflection2
		phase2 = -1.0;
	elseif dx < dxInflection2
		phase2 = 1.0;
	else
		phase2 = 0.0;
	endif
