#!/bin/env fish

cd (git rev-parse --show-toplevel 2>/dev/null)
source .env.fish

cmake -S . -B build/  --preset=default && cmake --build build/ && ./build/Calculator

