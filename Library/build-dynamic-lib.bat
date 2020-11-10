@echo off

set BAT_BASE_PATH=%~dp0
set PRJ_PATH=%BAT_BASE_PATH%
set BIN_PATH=%PRJ_PATH%\bin
set SRC_PATH=%PRJ_PATH%\src
set INC_PATH=%PRJ_PATH%\include
set APP_PATH="%BIN_PATH%\mylib.dll"

@REM if exist "%BIN_PATH%" (
@REM     RD /S /Q "%BIN_PATH%"
@REM )

@REM MD "%BIN_PATH%"

clang ^
    -I "%INC_PATH%" ^
    -o %APP_PATH% "%SRC_PATH%\*.c" ^
    --shared

if "%~1" == "-pre" (
    call "%BAT_BASE_PATH%\precompiled.bat"
)
