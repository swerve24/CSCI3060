#!/bin/bash

echo "CSCI 3060 - Lab 1"

#takes one argument (file_name)
if [ "$1"  != "" ]; then
	echo "Argument provided: $1"

	#for each file in the current directory:
	#diff file and file_name
	#if they are the same:
		#echo "file and file_name are the same"
	#	echo "File and file_name are the same"
	#else
		#append the diff to a log file

else
	echo "Please enter one argument"
fi