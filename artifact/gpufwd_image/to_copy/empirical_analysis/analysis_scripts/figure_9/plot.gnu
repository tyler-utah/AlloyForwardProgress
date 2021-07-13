set terminal pdf enhanced font 'Times,18' size 12, 3
set output 'bar.pdf'

set style data histogram
set style histogram cluster gap 1
set logscale y 2

set style fill solid border rgb "black"
set style histogram cluster gap 3
set yrange [.55:*]
set xrange [-.7:7.5]
set datafile separator ","
set key outside;
set key right top;
#set xlabel "Device"
set ylabel "Number of non-terminating tests"

plot 'output.dat' using 2:xtic(1) title col linecolor rgb "#ff6600",\
     '' using 3:xtic(1) title col linecolor rgb "#bbff6600",\
     '' using 6:xtic(1) title col linecolor rgb "#73b8e1",\
     '' using 7:xtic(1) title col linecolor rgb "#bb73b8e1",\
     '' using 4:xtic(1) title col linecolor rgb "#5c5c5d",\
     '' using 5:xtic(1) title col linecolor rgb "#bb5c5c5d"