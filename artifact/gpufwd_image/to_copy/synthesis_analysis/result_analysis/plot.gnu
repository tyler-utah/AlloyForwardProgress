set term pdf enhanced font 'Times,18' size 4,3
set output 'output.pdf'

set key outside;
set key right top;
set key autotitle columnheader

set yrange [0:100]
set xrange [-.7:2.6]
set ylabel "total % of tests"

set arrow from 0.5, graph 0 to 0.5, graph 1 nohead

set style data histogram
set style histogram rowstacked
set style fill solid border -1
set boxwidth 0.5

plot 'data.dat' using 2:xtic(1),\
     '' using 3,\
     '' using 7,\
     '' using 6,\
     '' using 5,\
     '' using 4
