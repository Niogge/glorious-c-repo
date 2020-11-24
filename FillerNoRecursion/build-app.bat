@echo off

set BAT_BASE_PATH=%~dp0
set PRJ_PATH=%BAT_BASE_PATH%
set BIN_PATH=%PRJ_PATH%\bin
set SRC_PATH=%PRJ_PATH%\app
set INC_PATH=%PRJ_PATH%\include
set APP_PATH="%BIN_PATH%\app.exe"

clang ^
    -I "%INC_PATH%" ^
    -o %APP_PATH% "%SRC_PATH%\*.c" ^
    -L "%BIN_PATH%" ^
    -l filler

if "%~1" == "-pre" (
    call "%BAT_BASE_PATH%\precompiled.bat"
)
