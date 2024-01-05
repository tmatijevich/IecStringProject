<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio FileVersion="4.9"?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1">
    <Task Name="ACopy1C" Source="Source.Performance.ACopy1C.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="ACopy2Iec" Source="Source.Performance.ACopy2Iec.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="ACopy3Brs" Source="Source.Performance.ACopy3Brs.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="ACopy4Lib" Source="Source.Performance.ACopy4Lib.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="BCat1C" Source="Source.Performance.BCat1C.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="BCat2Iec" Source="Source.Performance.BCat2Iec.prg" Memory="UserROM" Language="IEC" Debugging="true" />
    <Task Name="BCat3Brs" Source="Source.Performance.BCat3Brs.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="BCat4Lib" Source="Source.Performance.BCat4Lib.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="PerfCCopy" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="PerfBrCopy" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="PerfISDec" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="PerfBrDec" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="PerfISCopy" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#2" />
  <TaskClass Name="Cyclic#3" />
  <TaskClass Name="Cyclic#4" />
  <TaskClass Name="Cyclic#5" />
  <TaskClass Name="Cyclic#6" />
  <TaskClass Name="Cyclic#7" />
  <TaskClass Name="Cyclic#8" />
  <Libraries>
    <LibraryObject Name="IecString" Source="Libraries.IecString.lby" Memory="UserROM" Language="ANSIC" Debugging="false" />
    <LibraryObject Name="AsBrStr" Source="Libraries.AsBrStr.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="astime" Source="Libraries.astime.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="runtime" Source="Libraries.runtime.lby" Memory="UserROM" Language="binary" Debugging="true" />
  </Libraries>
</SwConfiguration>