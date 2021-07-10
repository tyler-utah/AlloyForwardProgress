#!/bin/bash
if [ $# -eq 0 ]
then
	echo "Supply folder name to process"
	exit 0
fi

shopt -s nullglob

source="${BASH_SOURCE%/*}/"
for f in $1/*/
do
	for f2 in $f/*.txt
	do
		python $source/RemoveENDSpace.py $f2
	done 		
done
