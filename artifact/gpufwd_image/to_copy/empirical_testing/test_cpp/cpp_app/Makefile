CXX=g++

all:
	$(CXX) -L /usr/local/opt/llvm/lib/ -std=c++17 -lpthread -DMAX_THREADS=6 -o main_occupancy main.cpp -lpthread
	$(CXX) -L /usr/local/opt/llvm/lib/ -std=c++17 -lpthread -DMAX_THREADS=768 -o main_over_occupancy main.cpp -lpthread

clean:
	rm -f *~ main_occupancy main_over_occupancy
