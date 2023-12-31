
PROGRAM _CYCLIC
	DoublePromotionValue := FloatValue;
	IecStringFloat(LibFloatText, SIZEOF(LibFloatText), FloatValue);
	brsftoa(FloatValue, ADR(BrsFloatText));
END_PROGRAM
