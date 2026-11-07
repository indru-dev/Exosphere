@echo off
:: A CMake Layer, because I was not satisfied with CMakePresets.json

if '%1'=='' (
    REM exit the process
    echo No arguments provided. Provide an argument: --setup, --build, --run or --install.
    exit /b
)

if '%1'=='--setup' (
    REM Tell CMake to Configure
    goto Setup
)


Setup:
if

