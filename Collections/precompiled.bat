@echo off

set PRJ_PATH=%~dp0
set SRC_PATH=%PRJ_PATH%\src
set INC_PATH=%PRJ_PATH%\include
set DEBUG_PATH=%PRJ_PATH%\debug

if exist "%DEBUG_PATH%" (
    RD /S /Q "%DEBUG_PATH%"
)


MD "%DEBUG_PATH%"

clang -D_INC_STDIO -I "%INC_PATH%" -E "%SRC_PATH%\*.c">"%DEBUG_PATH%\precompiled.dbg" 

REM this stuff is called both in run.bat and build.bat 
REM IF and ONLY IF you call them as "run.bat -pre" and "build.bat -pre"