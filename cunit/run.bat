@echo off
set BAT_BASE_PATH=%~dp0

if "%~1" == "-pre" (
    set BUILD_PARAM="-pre"
) else (
     set BUILD_PARAM=""
)
call "%BAT_BASE_PATH%\build.bat" %BUILD_PARAM%
IF %ERRORLEVEL% NEQ 0 ( Exit /B -1)

REM CLS
call "%BAT_BASE_PATH%\bin\main.exe"

