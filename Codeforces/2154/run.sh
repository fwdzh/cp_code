#!/bin/bash
g++ -std=c++20 -Wall -Wextra "$1".cpp -o ./bin/"$1" && ./bin/"$1"