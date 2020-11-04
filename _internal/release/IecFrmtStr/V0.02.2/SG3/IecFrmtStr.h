/* Automation Studio generated header file */
/* Do not edit ! */
/* IecFrmtStr 0.02.1 */

#ifndef _IECFRMTSTR_
#define _IECFRMTSTR_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _IecFrmtStr_VERSION
#define _IecFrmtStr_VERSION 0.02.1
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsBrStr.h"
#endif
#ifdef _SG4
		#include "AsBrStr.h"
#endif
#ifdef _SGC
		#include "AsBrStr.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define FORMAT_STR_MAX_INDEX_ARGS 4U
 #define FORMAT_STR_STR_LEN_ARGS 80U
#else
 _GLOBAL_CONST unsigned char FORMAT_STR_MAX_INDEX_ARGS;
 _GLOBAL_CONST unsigned char FORMAT_STR_STR_LEN_ARGS;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct FormatStringArgumentsType
{	plcbit b[5];
	float r[5];
	signed long i[5];
	plcstring s[5][81];
} FormatStringArgumentsType;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC unsigned long IecFormatString(unsigned long pDestination, unsigned long DestinationLength, unsigned long pSource, unsigned long pArguments);


#ifdef __cplusplus
};
#endif
#endif /* _IECFRMTSTR_ */

