@echo off

set BAT_BASE_PATH=%~dp0
set PRJ_PATH=%BAT_BASE_PATH%
set BIN_PATH=%PRJ_PATH%\bin
set APP_PATH=%BIN_PATH%\tests.exe
set INC_PATH=%PRJ_PATH%\include
set TEST_PATH=%PRJ_PATH%\tests
set TEST_INC_PATH=%BAT_BASE_PATH%\..\cunit\include


clang ^
    -I "%INC_PATH%" ^
    -I "%TEST_INC_PATH%"^
    -o "%APP_PATH%" "%TEST_PATH%\*.c"^
    -L "%BIN_PATH%" ^
    -l aiv-collections

if "%~1" == "-pre" (
    call "%BAT_BASE_PATH%\precompiled.bat"
)