# IecStringProject

IecStringProject is an Automation Studio project for developing, testing, and releasing the [IecString](https://github.com/tmatijevich/IecString) library.

# Performance Tests

```mermaid
gantt
    title [us] 100 Calls to Copy 80 Characters - AR E4.92 - Intel ATOM E640T 1 GHz
    dateFormat X
    axisFormat %s
    section strcpy
    32 : 0, 32
    section IEC assignment
    32 : 0, 32
    section brsstrcpy
    68 : 0, 68
    section IecStringCopy
    64 : 0, 64
```

```mermaid
gantt
    title [us] 100 Calls to Concatenate 80 Characters to Length of 80 - AR E4.92 - Intel ATOM E640T 1 GHz
    dateFormat X
    axisFormat %s
    section strcat
    57 : 0, 57
    section CONCAT
    240 : 0, 240
    section brsstrcat
    116 : 0, 116
    section IecStringConcat
    92 : 0, 92
```

# Unit Tests

