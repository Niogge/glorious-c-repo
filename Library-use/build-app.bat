@echo off

set BAT_BASE_PATH=%~dp0
set PRJ_PATH=%BAT_BASE_PATH%
set BIN_PATH=%PRJ_PATH%\bin
set SRC_PATH=%PRJ_PATH%\src
set INC_PATH=%PRJ_PATH%\include
set APP_PATH=%BIN_PATH%\app.exe
set LIB_PATH=%PRJ_PATH%\..\Collections-dll

if exist "%BIN_PATH%" (
    RD /S /Q "%BIN_PATH%"
)

MD "%BIN_PATH%"

clang ^
    -I "%INC_PATH%" ^
    -I "%LIB_PATH%\include" ^
    -o "%APP_PATH%" "%SRC_PATH%\*.c" ^
    -L "%LIB_PATH%\bin" ^
    -l aiv-collections

COPY "%LIB_PATH%\bin\aiv-collections.dll" "%BIN_PATH%"

if "%~1" == "-pre" (
    call "%BAT_BASE_PATH%\precompiled.bat"
)

