@echo off
chcp 65001 > nul

echo Setting up environment...
set PATH=d:\Strawberry\c\bin;d:\Strawberry\perl\bin;%PATH%

echo Checking Visual C++ Runtime...
if not exist "C:\Windows\System32\msvcp140.dll" (
    echo Warning: Visual C++ Runtime Library might be missing.
    echo Please install Visual C++ Redistributable from:
    echo https://aka.ms/vs/17/release/vc_redist.x64.exe
    exit /b 1
)

echo Cleaning build directory...
if exist build rmdir /s /q build
mkdir build
cd build

echo Running CMake...
cmake .. -G "Ninja"
if errorlevel 1 (
    echo CMake configuration failed
    exit /b 1
)

echo Building project...
cmake --build . --config Debug
if errorlevel 1 (
    echo Build failed
    exit /b 1
)

echo Running tests...
.\tests.exe
if errorlevel 1 (
    echo Tests failed
    exit /b 1
)

echo All tests completed
cd ..
