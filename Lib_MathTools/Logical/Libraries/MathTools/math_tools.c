#include "MathTools.h"
#include <math.h>

/* 
 * Internal function 
 * Utilize the implicit conversion from chars/shorts to longs
 */
static signed long WrapInteger(signed long inputValue, signed long lowerBound, signed long upperBound) {
	/* Static functions are functions only visible to other functions in the file */
	
	if(lowerBound <= upperBound) {
		signed long total 		= upperBound - lowerBound + 1;
		signed long distance 	= inputValue - lowerBound;
		signed long offset 		= distance % total;
		
		if(offset >= 0) 
			return lowerBound + offset;
		else
			return upperBound + offset + 1; // +1 to include the upper bound during subtraction
	}
	
	else
		return 0;
		
}

/*
 * Each function will return zero if the bounds exceed data type limits
 * or the lower bound exceeds the upper bound
 */

/* USINT wrap */
unsigned char Math_WrapUSINT(signed long Value, signed long LowerBound, signed long UpperBound) {
	if(LowerBound < 0 || LowerBound > 255 || UpperBound < 0 || UpperBound > 255)
		return 0;
	else
		return (unsigned char)WrapInteger(Value, LowerBound, UpperBound);
}

/* SINT wrap */
signed char Math_WrapSINT(signed long Value, signed long LowerBound, signed long UpperBound) {
	if(LowerBound < -128 || LowerBound > 127 || UpperBound < -128 || UpperBound > 127)
		return 0;
	else
		return (signed char)WrapInteger(Value, LowerBound, UpperBound);
}

/* UINT wrap */
unsigned short Math_WrapUINT(signed long Value, signed long LowerBound, signed long UpperBound) {
	if(LowerBound < 0 || LowerBound > 65535 || UpperBound < 0 || UpperBound > 65535)
		return 0;
	else
		return (unsigned short)WrapInteger(Value, LowerBound, UpperBound);
}

/* INT wrap */
signed short Math_WrapINT(signed long Value, signed long LowerBound, signed long UpperBound) {
	if(LowerBound < -32768 || LowerBound > 32767 || UpperBound < -32768 || UpperBound > 32767)
		return 0;
	else
		return (signed short)WrapInteger(Value, LowerBound, UpperBound);
}


/* 
 * Internal function 
 * Utilize the implicit conversion from floats to doubles
 */
double WrapDouble(double inputValue, double lowerBound, double upperBound) {
	if(upperBound > lowerBound){
		double distance = inputValue - lowerBound;
		double total = upperBound - lowerBound;
		double offset = distance - trunc(distance / total) * total;
		return (distance >= 0.0)? (lowerBound + offset) : (upperBound + offset);
	} else
		return 0.0;
}

/* REAL wrap */
float Math_WrapREAL(double Value, double LowerBound, double UpperBound) {
	return (float)WrapDouble(Value, LowerBound, UpperBound);
}

/* LREAL wrap */
double Math_WrapLREAL(double Value, double LowerBound, double UpperBound) {
	return WrapDouble(Value, LowerBound, UpperBound);
}
