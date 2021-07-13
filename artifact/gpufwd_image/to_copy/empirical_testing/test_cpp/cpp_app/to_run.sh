set -x
mkdir -p results
lscpu > results/ae_lscpu
./main_occupancy > results/ae_occupancy.txt
./main_over_occupancy > results/ae_over_occupancy.txt
