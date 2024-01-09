<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio FileVersion="4.9"?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1">
    <Task Name="PerfCCopy" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="PerfBrCopy" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="PerfISDec" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="PerfBrDec" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="PerfISCopy" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#2">
    <Task Name="ACopy1C" Source="Source.Performance.ACopy1C.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="ACopy2Iec" Source="Source.Performance.ACopy2Iec.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="ACopy3Brs" Source="Source.Performance.ACopy3Brs.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="ACopy4Lib" Source="Source.Performance.ACopy4Lib.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="BCat1C" Source="Source.Performance.BCat1C.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="BCat2Iec" Source="Source.Performance.BCat2Iec.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="BCat3Brs" Source="Source.Performance.BCat3Brs.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="BCat4Lib" Source="Source.Performance.BCat4Lib.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="EDec2Iec" Source="Source.Performance.EDec2Iec.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="EDec3Brs" Source="Source.Performance.EDec3Brs.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="EDec4Lib" Source="Source.Performance.EDec4Lib.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="FFp2Iec" Source="Source.Performance.FFp2Iec.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="FFp3Brs" Source="Source.Performance.FFp3Brs.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="FFp4Lib" Source="Source.Performance.FFp4Lib.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#3" />
  <TaskClass Name="Cyclic#4" />
  <TaskClass Name="Cyclic#5" />
  <TaskClass Name="Cyclic#6" />
  <TaskClass Name="Cyclic#7" />
  <TaskClass Name="Cyclic#8" />
  <Binaries>
    <BinaryObject Name="TCData" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="udbdef" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="asfw" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="sysconf" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="arconfig" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="ashwd" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="ashwac" Source="" Memory="UserROM" Language="Binary" />
  </Binaries>
  <Libraries>
    <LibraryObject Name="IecString" Source="Libraries.IecString.lby" Memory="UserROM" Language="ANSIC" Debugging="false" />
    <LibraryObject Name="AsBrStr" Source="Libraries.AsBrStr.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="astime" Source="Libraries.astime.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="runtime" Source="Libraries.runtime.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="standard" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="asieccon" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
  </Libraries>
</SwConfiguration>