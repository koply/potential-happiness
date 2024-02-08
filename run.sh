#!/bin/bash

if [[ -n "$1" ]] 
then
	a=${1%.*}
	gcc $1 -o ./out/$a -lm
	./out/$a
else
	echo "please specify a c file"
fi
