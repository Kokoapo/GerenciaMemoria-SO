@echo off

REM Compile o código C++
g++ main.cpp -o bin/main.exe
g++ criar_reference_string.cpp -o bin/ref_string.exe

REM Verifique se a compilação foi bem-sucedida
if %ERRORLEVEL% equ 0 (
    echo Compilation successful. Exiting...

) else (
    echo Compilation failed. Exiting...
)
