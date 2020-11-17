@echo off
set BAT_BASE_PATH=%~dp0

@REM if "%~1" == "-pre" (
@REM     set BUILD_PARAM="-pre"
@REM ) else (
@REM      set BUILD_PARAM=""
@REM )
@REM call "%BAT_BASE_PATH%\build-app.bat" %BUILD_PARAM%
@REM IF %ERRORLEVEL% NEQ 0 ( Exit /B -1)

REM CLS
call "%BAT_BASE_PATH%\bin\app.exe"

