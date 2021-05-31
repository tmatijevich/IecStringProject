# LibIecFrmtStr

A sample Automation Studio project demonstrating the IecFrmtStr library. This repository also serves the development of the IecFrmtStr library with [release updates](https://github.com/tmatijevich/LibIecFrmtStr/releases).

- Clone the project: `git@github.com:tmatijevich/LibIecFrmtStr.git`
	- Alternatively: `ssh://git@ssh.github.com:443/tmatijevich/LibIecFrmtStr.git`
- [Download IecFrmtStr library](https://github.com/tmatijevich/LibIecFrmtStr/releases/download/0.2.4/IecFrmtStr.zip)
- [Download LibIecFrtmStr sample project](https://github.com/tmatijevich/LibIecFrmtStr/releases/download/0.2.4/LibIecFrmtStr.zip)

## IecFrmtStr

This library contains the `IecFormatString()` function to perform [C's `printf`-esk](https://www.cplusplus.com/reference/cstdio/printf/) string operations in the [IEC 61131-3 Structured Text](https://en.wikipedia.org/wiki/Structured_text) language for Automation Studio programs. 

Format strings using the keys `%b`, `%r`, `%i`, and `%s` for BOOLs, REALs, DINTs, and STRINGs. Up to 5 (0..4) type keys can be used in a single message, pending the destination length. If the destination length is exceeded upon inserting the message arguments, the resulting formatted message will be truncated.

### Example


```
MessageArguments.b[0] := FALSE; // BOOL
MessageArguments.r[0] := 78.768; // REAL
MessageArguments.i[0] := -2144327918; // DINT
MessageArguments.s[0] := 'INIT'; // STRING

sConstructMessage := 'Status %b, Temp %r F, Code %i, State %s';

IecFormatString(pDestination := ADR(sFormattedMessage), 
                DestinationLength := SIZEOF(sFormattedMessage), 
                pSource := ADR(sConstructMessage), 
                pArguments := ADR(MessageArguments));
```

1. Download the LibIecFrmtStr Automation Studio project and perform an offline installation.
2. Open the watch window for the Sample task.
3. The `IecFormatString` call assigns `'Status FALSE, Temp 78.768 F, Code -2144327918, State INIT'` to `sFormattedMessage`

## Git
- [Install and setup Git](https://tmatijevich.github.io/gfw-tutorial/)
- [Setup gitignore for your repository](https://gist.github.com/tmatijevich/453436f1e6abc62a3d052d9b03f9db58)

## Automation Studio
Version 4.9.3.144 SP

## Automation Runtime

Component 				| Project 			| Config - Simulation	
------------------------|-------------------|-----------------------
Automation Runtime		| x					| C4.90 
Visual Components		| x 				| n/d 
mapp Motion 			| n/d 				| x 
mapp View 				| n/d 				| x 
mapp Services 			| n/d 				| x 
ACP10 ARNC0				| n/d 				| x 
mapp Control 			| n/d 				| x 
mapp Cockpit 			| n/d 				| x 
Safety Release 			| n/d 				| x 

