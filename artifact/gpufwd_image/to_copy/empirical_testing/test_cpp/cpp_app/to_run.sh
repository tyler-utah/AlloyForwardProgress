set -x
lscpu > results/toucan_lscpu
./main_occupancy > results/ae_occupancy.txt
./main_over_occupancy > results/ae_over_occupancy.txt