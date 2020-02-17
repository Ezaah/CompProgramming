#!/bin/bash

for((i = 0; i < 1000000; ++i)) do
    echo $i
    ./gen.o $i > input5
    diff -w <(./b.o < input5) <(./brute.o < input5) || break

done