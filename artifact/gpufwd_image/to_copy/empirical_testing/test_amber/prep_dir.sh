rm -rf ./results/*

mkdir -p ../ALL_tests_tmp
mkdir -p ../ALL_tests_tmp/2_thread_2_instruction
mkdir -p ../ALL_tests_tmp/2_thread_3_instruction
mkdir -p ../ALL_tests_tmp/2_thread_4_instruction
mkdir -p ../ALL_tests_tmp/3_thread_3_instruction
mkdir -p ../ALL_tests_tmp/3_thread_4_instruction

cp ../ALL_tests_flat/2t_2i*/*.txt ../ALL_tests_tmp/2_thread_2_instruction/

cp ../ALL_tests_flat/2t_3i*/*.txt ../ALL_tests_tmp/2_thread_3_instruction/

cp ../ALL_tests_flat/2t_4i*/*.txt ../ALL_tests_tmp/2_thread_4_instruction/

cp ../ALL_tests_flat/3t_3i*/*.txt ../ALL_tests_tmp/3_thread_3_instruction/

cp ../ALL_tests_flat/3t_4i*/*.txt ../ALL_tests_tmp/3_thread_4_instruction/
