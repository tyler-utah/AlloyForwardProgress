rm -rf ../out/$1
rm -f progress_to_run.als
cp progress.als progress_to_run.als
echo $2 >> progress_to_run.als
java -classpath org.alloytools.alloy.dist/target/org.alloytools.alloy.dist.jar edu.mit.csail.sdg.alloy4whole.CreateTests out/$1 progress_to_run.als
