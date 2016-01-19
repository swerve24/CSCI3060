#!/bin/bash

echo "CSCI 3060 - Lab 1"

#takes one argument (file_name)
if [ "$#"  == 1 ]; then
	echo "Argument provided: $1"
	FILE_NAME = "$1"

	#for each file in the current directory:
	CURRENT_DIR = pwd
	#diff file and file_name
	for FILES in $CURRENT_DIR do
	#if they are the same:
	if [ diff $FILE_NAME/$FILES == ""]; then
		#echo "file and file_name are the same"
		echo "File and file_name (argument) are the same"
	else
		#append the diff to a log file
	done

else
	echo "Please enter ONE argument."
fi