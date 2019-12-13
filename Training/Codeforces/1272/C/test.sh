#!/bin/bash

for((i = 0; i < 1000000; ++i)) do
    echo $i
    ./gen.o $i > input5
    diff -w <(./c.o < input5) <(./exp.o < input5) || break

done