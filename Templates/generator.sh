#!/bin/bash

for((i = 0; i < 10; i++)) do
    ran=$RANDOM
    echo $ran
    ./gen.o $ran > input/input0$i.txt
    ./main.o < input/input0$i.txt > output/output0$i.txt
done