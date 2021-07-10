#!/bin/bash
# Script to process tests, generate png/pdfs and process labels

if [ $# -eq 0 ]
then
	echo "Supply folder name to process"
	exit 0
fi

shopt -s nullglob

str="_processed"
newname="$1$str"

rm -rf $newname
cp -r $1 $newname
rm -rf $newname/../checker_files
mkdir $newname/../checker_files
mkdir $newname/distinguishing
mkdir $newname/csv

source="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
count=0
for f in $newname/*/
do
	for f2 in $f/*.dot
	do
	if [[ $f2 =~ *_simple* ]]
	then
		:
	else
		echo `dirname $f2`/`basename $f2 .dot`

		# Make Dot, PNG, PDF files
		python $source/DotModify.py $f2
		v2=${f2%.dot}
		dot -Tpdf ${v2}_simple.dot -o $v2.pdf
		dot -Tpng ${v2}_simple.dot -o $v2.png
		cp $v2.xml ${v2}xml.txt

		# Getting some useful variables for parameters
		folderN=${f2%/*}
		v3=${f2##*/}
		index=${v3%.dot}
		# Make files for CADP
		python $source/CADPGen.py $folderN $index $source

		# Process CADP files into labels
		(cd $folderN/checker && svl test_${index}.svl > labels_${index}_output.txt)
		#(cd $folderN/checker && python ../../../../../processing/ProcessLabels.py labels_${index}_output.txt $index)
		(cd $folderN/checker && python ${source}/ProcessLabels.py labels_${index}_output.txt $index)

		# Make dot files from CADP graphs (convert to PDF manually as needed)
		(cd $folderN/checker && for i in *bcg ; do bcg_io $i -graphviz `basename $i .bcg`.dot ; done )
		for f3 in $folderN/checker/*.dot
		do
			python $source/fixDotSyntax.py $f3 #Remove extra "" from dot files so they can compile
		done

		# Move files to a different folder to clean test folder somewhat
		(cd $folderN/checker && cp labels_${index}.txt ../label_${index}.txt)
		(cd $folderN && mv checker ../../checker_files/$index)

		# Make Amber file (no saturation) for test (thanks Hari!)
		python3 $source/amber_test_generation.py $v2.txt $v2

		count=`expr $count + 1`
	fi
	done 		
done

# Convert scheduler results to CSV for comparison
python $source/CreateCSV.py $newname OBE
python $source/CreateCSV.py $newname HSA
python $source/CreateCSV.py $newname HSA_OBE
python $source/CreateCSV.py $newname LOBE
python $source/CreateCSV.py $newname WEAK_FAIR

python $source/CreateCSV.py $newname OBE_STRONG
python $source/CreateCSV.py $newname HSA_STRONG
python $source/CreateCSV.py $newname HSA_OBE_STRONG
python $source/CreateCSV.py $newname LOBE_STRONG
python $source/CreateCSV.py $newname STRONG_FAIR


# Copy HTML (with appropriate changes) to test folder
python $source/HTMLGen.py $source/testExplorer.html $newname/testExplorer.html $count
