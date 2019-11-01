#!/bin/bash

oldDir="/home/ezaah/Documents/Codes/Competencias/Problems/Contests/contest_creator/"
for letter in {A..Z} 
do
	echo "Copying template to problem" $letter
	mkdir $letter
	cd $letter
	cp $oldDir/template.cpp $letter.cpp
	touch input1.in
	touch output1.ans
	cd ..
	if [ $letter = $1 ]
		then
		       	break
	       	fi

done
