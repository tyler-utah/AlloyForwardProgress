#!/bin/bash
if [ $# -eq 0 ]
then
	echo "Supply folder name to process"
	exit 0
fi

shopt -s nullglob

source="${BASH_SOURCE%/*}"
for f in $1/*
do
	for f2 in $f/*.xml
	do
	        folderN=${f2%/*}
		fileName=${f2##*/}
		index=${fileName%.xml}

		python $source/Converter.py $folderN $index
	done 		
done
