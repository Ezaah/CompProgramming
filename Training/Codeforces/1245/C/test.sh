#!/bin/bash

for((i = 0; i < 1000000; ++i)) do
    echo $i
    ./gen $i > input5.in
    ./main < input5.in > output.log || break

done