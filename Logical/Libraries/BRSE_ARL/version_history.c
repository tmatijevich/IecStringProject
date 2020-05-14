/*! \file version_history.c */

/*! \page History
\section History
\par V1.00
\arg Implemented a buffered logbook writer
\par V1.01
\arg Splitted the source file into several files
\arg renamed MsgData to Arguments, changed the String datatype to UDINT (string pointer)
\par V1.02
\arg added documentation in source files.
\arg Changed Arguments to Arguments_typ
\par V1.03
\arg Removed dependency on RtkLib
\arg Several buffered logbooks can be used (identified by a unique ID)
\par V1.04
\arg Version created for AS3.0
\par V1.05
\arg Using mystring.h instead of string.h to avoid -lc build options in the phtysical view.
\par V1.06
\arg The problem with string.h has been solved in runtime versions >= 2.95, so string.h is used instead of mystring.
\par V1.07
\arg Changed layout of the library files (in Explorer) to support AS3 library setup.
\par V1.08
\arg Changed from FIFO to circular buffer. It overwrites the oldest entry when buffer gets full, this gives the possibility
to continuously logg to the buffer and only transfer the data to the user logg when an error occurs. This uses less
CPU time then constantly writing to the user logg. Please see \ref buffer information. 
\par V1.09
\arg Added new function block BRSE_ARL_DebugInfo which displays the internal stucture including the AsArLog FBs for internal usage.
\par V1.10
\arg Library dependency has been changed from AsString to AsBrStr, so that the conflictions can be avoided with ANSI-C standard functions(atof, atoi etc.)
\par V1.11
\arg Replaced (void *) with (UDINT) to avoid error in Lint
\par V1.12
\arg in function unsigned short BRSE_ARL_Cyclic(unsigned short ID) local variables are initialized
\par V1.13
\arg Much less space will be used when allocating the logger entries
\arg Logger_typ: the buffer is changed to 1 element.
\arg LoggerbookEntry_typ: the ErrorMsg is changed to 1 element.
*/
