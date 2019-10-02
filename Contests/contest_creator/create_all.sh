#!/bin/bash

oldDir="/home/ezaah/Documents/Codes/Competencias/Problems/Contests/contest_creator/"

for letter in $(eval echo "{A..$1}")
do
	
	mkdir $letter
	cd $letter
	cp $oldDir/template.cpp $letter.cpp
	touch input1.in
	touch output1.ans
	cd ..
done
