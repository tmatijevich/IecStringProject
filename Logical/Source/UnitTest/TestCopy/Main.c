#include <bur/plc.h>
#include <Variablesvar.h>
#include <IecString.h>

void _CYCLIC ProgramCyclic(void) {
    MyStatus = IecStringCopy(String1, MySize, String2);
}
