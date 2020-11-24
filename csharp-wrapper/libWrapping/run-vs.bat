@echo off
set BAT_BASE_PATH=%~dp0

call "%BAT_BASE_PATH%\build-dynamic-lib.bat"

COPY /Y "%BAT_BASE_PATH%\bin\mylib.dll" "%BAT_BASE_PATH%\..\CsharpWrapper\bin\x64\Debug\"