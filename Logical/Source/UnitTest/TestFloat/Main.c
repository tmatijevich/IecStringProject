#include <bur/plc.h>
#include <Variablesvar.h>
#include <IecString.h>
#include <AsBrStr.h>
#include <stdint.h>
#include <math.h>

void _CYCLIC ProgramCyclic(void) {
    IecStringFloat(LibFloatText, sizeof(LibFloatText), FloatValue, 0, 
        Precision, 0);
    brsftoa(FloatValue, (uint32_t)BrsFloatText);
    PromotionToDouble = FloatValue;
    FloatRaw = *(uint32_t*)&FloatValue;

    if (TestInfinity) {
        TestInfinity = 0;
        FloatValue *= 1.0e38f;
    }

    if (TestNotANumber) {
        TestNotANumber = 0;
        FloatValue /= 0.0f;
    }

    Log10Value = log10f(FloatValue);
}
