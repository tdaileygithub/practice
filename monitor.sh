#!/bin/bash
find . -name 'main.cpp' -or -name 'CMakeLists.txt' | entr ./build.sh
