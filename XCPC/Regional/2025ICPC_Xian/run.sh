#!/usr/bin/bash
g++ -std=c++20 -Wall -Wextra -DLOCAL $1.cpp -o $1
./$1