#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

OUTPUT="tests"

echo "Compiling tests..."
g++ -std=c++17 -Wno-deprecated -o "$OUTPUT" tests.cpp ../tyme/base.cpp ../tyme/culture.cpp ../tyme/cycle.cpp ../tyme/solar.cpp ../tyme/lunar.cpp ../tyme/eightchar.cpp ../tyme/childlimit.cpp ../tyme/festival.cpp ../tyme/rabbyung.cpp ../tyme/seasonal.cpp ../tyme/util.cpp

echo "Running tests..."
./"$OUTPUT"
