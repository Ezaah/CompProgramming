#!/bin/bash

n=1
for i in {A..Z}; do
	if ((n > "$1" )); then
		break
	fi
	echo "Creating problem directory for problem number $n with letter $i ..."
	mkdir "$i"
	touch "$i/$i.cpp"
	touch "$i/input.in"
	touch "$i/output.ans"
	n=$((n+1))
done

