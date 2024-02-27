@echo off
setlocal enabledelayedexpansion

for /L %%i in (10, 10, 100) do (
    for %%f in (4 8 16 32) do (
        for %%l in (1 2 3 4) do (
            for %%a in (0 1) do (
                 start /b main.exe ref%%ilog%%l %%f %%a > "resultado/ref%%ilog%%l %%f %%a"
            )
        )
    )
)

endlocal
