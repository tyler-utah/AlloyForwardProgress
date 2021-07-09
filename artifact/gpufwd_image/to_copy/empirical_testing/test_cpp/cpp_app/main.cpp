#include <iostream>
#include <assert.h>
#include <atomic>
#include <thread>
#include <vector>
#include <chrono>
#include <pthread.h>
#include <functional>

using std_clock = std::chrono::system_clock;
using sec = std::chrono::duration<double>;
using namespace std;

//#define MAX_THREADS 6
#define TIME_OUT 30
#define INNER_ITERATIONS 30

atomic_uint *t_x;
atomic_uint *t_y;
atomic_int *t_count;
atomic_int *cpu_terminate;


vector<std::function<void(atomic_uint *, atomic_uint *, atomic_int *, int)> > kernels;
vector<string> kernel_names;

//std::function<void(atomic_uint *, atomic_uint *, atomic_int *, int)> to_call = plain_2t_2i_3;

//void init_kernels() {
//  kernel_names.push_back("plain_2t_2i_3");
//  kernels.push_back(plain_2t_2i_3);
//}
#include "kernels.cpp"
#include "kernel_init.h"

void initialize() {
  for (int i = 0; i < MAX_THREADS; i++) {
    t_x[i] = t_y[i] = 0;
  }
  t_count[0] = 0;
  cpu_terminate[0] = 0;
}

int main() {

  assert(MAX_THREADS % 2 == 0 && MAX_THREADS % 3 == 0);

  const auto total_start = std_clock::now();
    
  t_x = (atomic_uint*) malloc(sizeof(atomic_int)*MAX_THREADS);
  t_y = (atomic_uint*) malloc(sizeof(atomic_int)*MAX_THREADS);
  t_count = (atomic_int*) malloc(sizeof(atomic_int));
  cpu_terminate = (atomic_int*) malloc(sizeof(atomic_int));
  init_kernels();
  int total_killed = 0;



  for (int test = 0; test < kernels.size(); test++) {
    cout << "running test: " << kernel_names[test] << "\n";

    int success = 0;
    int killed = 0;
    for (int inner_i = 0; inner_i < INNER_ITERATIONS; inner_i++) {
      // initialize and launch test
      initialize();  
      vector<std::thread> launched;
      for (uint i = 0; i < MAX_THREADS; i++) {
	std::thread th (kernels[test], t_x, t_y, t_count, i);
	launched.push_back(std::move(th));
      }
      const auto start = std_clock::now();
      // Do we actually need to kill threads if they are hanging?
      bool hung = true;
      while (1) {
	if (atomic_load_explicit(t_count,memory_order_relaxed) == MAX_THREADS) {
	  hung = false;
	  break;
	}
	const sec duration = std_clock::now() - start;
	if (duration.count() > TIME_OUT) {
	  hung = true;
	  break;
	}
      }
      
      if (!hung) {
	cout << ".";
	success+=1;
	for (uint i = 0; i < MAX_THREADS; i++) {	  
	  launched[i].join();
	}
      }
      else {
	cout << "x";
	killed+=1;
	total_killed +=1;
	atomic_store_explicit(cpu_terminate, 1, memory_order_relaxed);
	for (uint i = 0; i < MAX_THREADS; i++) {	  
	  launched[i].join();
	}
	
      }
      
    }
    cout << "\n";
    cout << "success: " << success << endl;
    cout << "killed: " << killed << endl;
  }
  
  //plain_2t_2i_3(t_x, t_y, t_count);

  const sec duration = std_clock::now() - total_start;
  cout << "\n------------------\n";
  cout << "finished\n";
  cout << "tests ran: " << kernels.size() << "\n";
  cout << "iterations per test: " << INNER_ITERATIONS << "\n";
  cout << "total tests killed: " << total_killed << "\n";
  cout << "timeout: " << TIME_OUT << " s\n";
  cout << "threads: " << MAX_THREADS << "\n";
  cout << "total testing time: " << duration.count() << " s\n";
  
  cout << "\n";
  
  return 0;
}
