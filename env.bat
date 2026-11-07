@echo off
:: Sets persistent variables for the current session only.

REM Adds to path, so not recommended to use this file.

powershell -NoExit -Command "$env:Path += ';%CD%\bin\Exosphere.exe"
powershell -NoExit -Command "$env:Path += ';%CD%\emake.bat"


