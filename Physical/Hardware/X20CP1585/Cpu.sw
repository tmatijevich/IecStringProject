<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio FileVersion="4.9"?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1">
    <Task Name="PerfBase" Source="Source.Performance.PerfBase.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="PerfCCopy" Source="Source.Performance.PerfCCopy.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="PerfBrCopy" Source="Source.Performance.PerfBrCopy.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="PerfISCopy" Source="Source.Performance.PerfISCopy.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="PerfBrDec" Source="Source.Performance.PerfBrDec.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="PerfISDec" Source="Source.Performance.PerfISDec.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
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