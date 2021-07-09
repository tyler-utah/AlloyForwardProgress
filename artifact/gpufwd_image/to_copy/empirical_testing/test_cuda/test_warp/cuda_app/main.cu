#include <iostream>
#include <assert.h>
#include <atomic>
#include <thread>
#include <vector>
#include <chrono>
#include <pthread.h>
#include <functional>

// From: https://stackoverflow.com/questions/14038589/what-is-the-canonical-way-to-check-for-errors-using-the-cuda-runtime-api
#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess) 
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}

using std_clock = std::chrono::system_clock;
using sec = std::chrono::duration<double>;
using namespace std;

typedef void (*tfunc)(uint* arg0, uint* arg1, uint* arg2);

vector<string> kernel_names;
vector<tfunc*> kernels;

#include "kernels.h"
#include "kernel_init.h"

__global__ void test_launcher_kernel(uint * x, uint * y, uint* count, tfunc f) {
  f(x,y,count);
}

#define ITERS 20

int main(int argc, char **argv) {

  const unsigned int total_blocks = 1;
  const unsigned int bufferSize = (3 * sizeof(int));

  int t_num = 0;
  int i_num = 0;
  if (argc == 3) {
    t_num = atoi(argv[1]);
    i_num = atoi(argv[2]);
    printf("executing t: %d, i: %d\n",t_num, i_num);
  }

  uint *dBufferX;
  uint *dBufferY;
  uint *dBufferCounter;
  uint *hBufferX;
  uint *hBufferY;
  uint *hBufferCounter;
  
  gpuErrchk(cudaMalloc(&dBufferX, bufferSize)); 
  gpuErrchk(cudaMalloc(&dBufferY, bufferSize));
  gpuErrchk(cudaMalloc(&dBufferCounter, sizeof(uint)));

  hBufferX = (uint*) malloc(bufferSize);
  hBufferY = (uint*) malloc(bufferSize);
  hBufferCounter = (uint *) malloc(sizeof(uint));

  init_kernels();
  int total_killed = 0;
  tfunc host_function_ptr;
  assert(t_num <= kernel_names.size());
  assert(t_num <= kernels.size());

  // In case we want to do it iteratively
  //for (int t = t_num; t < kernel_names.size(); t++) {
  for (int t = t_num; t < t_num+1; t++) {
    cout << "running test: " << kernel_names[t] << "\n";
    gpuErrchk(cudaMemcpyFromSymbol(&host_function_ptr, *(kernels[t]), sizeof(tfunc)));

    int success = 0;
    int killed = 0;

    //for (int i = 0; i < ITERS; i++) {
    for (int i = i_num; i < i_num+1; i++) {
      //printf("test: %d, i: %d\n",t,i);
      //fflush(stdout);
      
      for (int i = 0; i < total_blocks; i++) {
	hBufferX[i] = 0;
	hBufferY[i] = 0;
      }
      hBufferCounter[0] = 0;
      
      gpuErrchk(cudaMemcpy(dBufferX, hBufferX, bufferSize, cudaMemcpyHostToDevice));
      gpuErrchk(cudaMemcpy(dBufferY, hBufferY, bufferSize, cudaMemcpyHostToDevice));
      gpuErrchk(cudaMemcpy(dBufferCounter, hBufferCounter, sizeof(uint), cudaMemcpyHostToDevice));

      test_launcher_kernel<<<1,3>>>(dBufferX, dBufferY, dBufferCounter, host_function_ptr);
      
      gpuErrchk(cudaDeviceSynchronize());
      
      gpuErrchk(cudaMemcpy(hBufferCounter, dBufferCounter, sizeof(uint), cudaMemcpyDeviceToHost));
      assert(*hBufferCounter == 3);
      //printf("found %d\n", *hBufferCounter);
    }
  }
    
  gpuErrchk(cudaFree(dBufferX));
  gpuErrchk(cudaFree(dBufferY));
  gpuErrchk(cudaFree(dBufferCounter));
  free(hBufferX);
  free(hBufferY);
  free(hBufferCounter);
  return 0;    
}
