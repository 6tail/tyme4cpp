@echo off
chcp 65001 > nul

set SCRIPT_DIR=%~dp0
cd /d "%SCRIPT_DIR%"

set OUTPUT=tests.exe

echo Compiling tests...
g++ -std=c++17 -Wno-deprecated -o %OUTPUT% tests.cpp ..\tyme\base.cpp ..\tyme\culture.cpp ..\tyme\cycle.cpp ..\tyme\solar.cpp ..\tyme\lunar.cpp ..\tyme\eightchar.cpp ..\tyme\childlimit.cpp ..\tyme\festival.cpp ..\tyme\rabbyung.cpp ..\tyme\seasonal.cpp ..\tyme\util.cpp
if errorlevel 1 (
    echo Compilation failed
    exit /b 1
)

echo Running tests...
.\%OUTPUT%
if errorlevel 1 (
    echo Tests failed
    exit /b 1
)

echo All tests completed
