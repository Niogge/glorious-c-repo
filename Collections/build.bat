@echo off

set BAT_BASE_PATH=%~dp0
set PRJ_PATH=%BAT_BASE_PATH%
set BIN_PATH=%PRJ_PATH%\bin
set SRC_PATH=%PRJ_PATH%\src
set INC_PATH=%PRJ_PATH%\include
set TEST_PATH=%PRJ_PATH%\tests
set TEST_INC_PATH=%BAT_BASE_PATH%\..\cunit\include

if exist "%BIN_PATH%" (
    RD /S /Q "%BIN_PATH%"
)

MD "%BIN_PATH%"

clang ^
    -I "%INC_PATH%" ^
    -I "%TEST_INC_PATH%"^
    -o "%BIN_PATH%\app.exe" "%SRC_PATH%\*.c" "%TEST_PATH%\*.c"

if "%~1" == "-pre" (
    call "%BAT_BASE_PATH%\precompiled.bat"
)