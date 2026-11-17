#!/usr/bin/env bash
# Script to compile and run all beginner C++ files sequentially

set -euo pipefail
cd "$(dirname "$0")"

echo "=========================================================="
echo "   BEGINNER C++ & OOP FOR ROBOTICS: RUN ALL EXAMPLES     "
echo "=========================================================="

for file in *.cpp; do
    exe="${file%.cpp}"
    echo ""
    echo "----------------------------------------------------------"
    echo ">>> COMPILING & RUNNING: $file"
    echo "----------------------------------------------------------"
    g++ -std=c++17 -Wall -Wextra "$file" -o "$exe"
    "./$exe"
done

echo ""
echo "=========================================================="
echo "   ALL 15 LESSONS COMPILED AND EXECUTED SUCCESSFULLY!     "
echo "=========================================================="

