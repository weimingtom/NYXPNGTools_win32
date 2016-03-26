@echo off

mkdir output >nul 2>&1
del /S /Q output\*.png >nul 2>&1

::	echo [process] input\%%~ni.png output\%%~ni.png
for %%i in (%cd%\input\*.png) do (

	fixpng.exe "input\%%~ni.png" "output\%%~ni.png"
)

@echo on
