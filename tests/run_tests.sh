#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

OUTPUT="tests"

echo "Compiling tests..."
g++ -std=c++17 -Wno-deprecated -o "$OUTPUT" tests.cpp ../tyme/tyme.cpp ../tyme/util.cpp

echo "Running tests..."
./"$OUTPUT"
