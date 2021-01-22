# LibIecFrmtStr

A sample Automation Studio project demonstrating the IecFrmtStr library. This repository also serves the development of the IecFrmtStr library with [release updates](https://github.com/tmatijevich/LibIecFrmtStr/releases).

Clone the project: `git@github.com:tmatijevich/LibIecFrmtStr.git`
- Alternatively: `ssh://git@ssh.github.com:443/tmatijevich/LibIecFrmtStr.git`

## IecFrmtStr

This library contains the `IecFormatString()` function to perform [C's `printf`-esk](https://www.cplusplus.com/reference/cstdio/printf/) string operations in the [IEC 61131-3 Structured Text](https://en.wikipedia.org/wiki/Structured_text) language for Automation Studio programs. 

Format strings using the keys `%b`, `%r`, `%i`, and `%s` for BOOLs, REALs, DINTs, and STRINGs. Up to 5 (0..4) type keys can be used in a single message, pending the destination length. If the destination length is exceeded upon inserting the message arguments, the resulting formatted message will be truncated.

### Example


```
MessageArguments.b[0] := TRUE; // BOOL
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
3. The `IecFormatString` call assigns `'Status TRUE, Temp 78.768 F, Code -2144327918, State INIT'` to `sFormattedMessage`