@echo off
set BAT_BASE_PATH=%~dp0

call "%BAT_BASE_PATH%\build-tests.bat"
IF %ERRORLEVEL% NEQ 0 ( Exit /B -1)

REM CLS
call "%BAT_BASE_PATH%\bin\tests.exe"

