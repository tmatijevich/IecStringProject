#include "MathTools.h"

/* Internal function */
static signed long fnWrapInteger(signed long inputValue, signed long lowerBound, signed long upperBound) {
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
unsigned char fnWrapUSINT(signed long Value, signed long LowerBound, signed long UpperBound) {
	if(LowerBound < 0 || LowerBound > 255 || UpperBound < 0 || UpperBound > 255)
		return 0;
	else
		return (unsigned char)fnWrapInteger(Value, LowerBound, UpperBound);
}

/* SINT wrap */
signed char fnWrapSINT(signed long Value, signed long LowerBound, signed long UpperBound) {
	if(LowerBound < -128 || LowerBound > 127 || UpperBound < -128 || UpperBound > 127)
		return 0;
	else
		return (signed char)fnWrapInteger(Value, LowerBound, UpperBound);
}

/* UINT wrap */
unsigned short fnWrapUINT(signed long Value, signed long LowerBound, signed long UpperBound) {
	if(LowerBound < 0 || LowerBound > 65535 || UpperBound < 0 || UpperBound > 65535)
		return 0;
	else
		return (unsigned short)fnWrapInteger(Value, LowerBound, UpperBound);
}

/* INT wrap */
signed short fnWrapINT(signed long Value, signed long LowerBound, signed long UpperBound) {
	if(LowerBound < -32768 || LowerBound > 32767 || UpperBound < -32768 || UpperBound > 32767)
		return 0;
	else
		return (signed short)fnWrapInteger(Value, LowerBound, UpperBound);
}
