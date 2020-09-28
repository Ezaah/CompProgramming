#!/bin/bash

mkdir input output
for((i = 0; i < 10; i++)) do
    ran=$RANDOM
    name=$(printf "%02d" $(($i+1)))
    echo $ran $name
    ./gen.o $ran > input/input$name.txt
    ./main.o < input/input$name.txt > output/output$name.txt
done
