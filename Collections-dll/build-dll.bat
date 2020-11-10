@echo off

set BAT_BASE_PATH=%~dp0
set PRJ_PATH=%BAT_BASE_PATH%
set BIN_PATH=%PRJ_PATH%\bin
set SRC_PATH=%PRJ_PATH%\src
set INC_PATH=%PRJ_PATH%\include
set APP_PATH=%BIN_PATH%\aiv-collections.dll


clang ^
    -DBUILD_DLL ^
    -I "%INC_PATH%" ^
    -o "%APP_PATH%" "%SRC_PATH%\*.c" ^
    --shared

