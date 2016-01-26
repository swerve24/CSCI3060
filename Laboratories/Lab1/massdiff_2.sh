#!/bin/bash

LOG_FILE = "lab1.log"
FILE_NAME=$1

for f in ./* do
	if diff $FILE_NAME $f > /dev/null; then
		echo "same file"
	else
		diff $FILE_NAME $f >> $LOG_FILE
	fi
done