<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio FileVersion="4.9"?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1">
    <Task Name="ACopy1C" Source="Source.Performance.ACopy1C.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="ACopy2Br" Source="Source.Performance.ACopy2Br.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="ACopy3IS" Source="Source.Performance.ACopy3IS.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="EDec2Br" Source="Source.Performance.EDec2Br.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="EDec3IS" Source="Source.Performance.EDec3IS.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
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