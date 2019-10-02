#!/bin/bash


for letter in {A..E}
do
	mkdir $letter
	cp template.cpp $letter/$letter.cpp
	touch $letter/input1.in
	touch $letter/output1.ans
done

