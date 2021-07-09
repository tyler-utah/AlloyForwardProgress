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

  const unsigned int total_blocks = 65532;
  const unsigned int bufferSize = (total_blocks * sizeof(int));

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

  // From https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#grid-synchronization-cg
  int dev = 0;
  int supportsCoopLaunch = 0;
  cudaDeviceGetAttribute(&supportsCoopLaunch, cudaDevAttrCooperativeLaunch, dev);
  cout << "supports cooperative launch: " << supportsCoopLaunch << endl;
  if (supportsCoopLaunch == 0) {
    cout << "device doesn't support cooperative launch, exiting" << endl;
    return 1;
  }

  // In case we want to do it iteratively
  //for (int t = t_num; t < kernel_names.size(); t++) {
  for (int t = t_num; t < t_num+1; t++) {
    cout << "running test: " << kernel_names[t] << "\n";
    gpuErrchk(cudaMemcpyFromSymbol(&host_function_ptr, *(kernels[t]), sizeof(tfunc)));

    int success = 0;
    int killed = 0;

    for (int i = i_num; i < i_num+1; i++) {
      
      for (int i = 0; i < total_blocks; i++) {
	hBufferX[i] = 0;
	hBufferY[i] = 0;
      }
      hBufferCounter[0] = 0;
      
      gpuErrchk(cudaMemcpy(dBufferX, hBufferX, bufferSize, cudaMemcpyHostToDevice));
      gpuErrchk(cudaMemcpy(dBufferY, hBufferY, bufferSize, cudaMemcpyHostToDevice));
      gpuErrchk(cudaMemcpy(dBufferCounter, hBufferCounter, sizeof(uint), cudaMemcpyHostToDevice));

      // From: https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#grid-synchronization-cg
      /// This will launch a grid that can maximally fill the GPU, on the default stream with kernel arguments
      int numBlocksPerSm = 0;
      // Number of threads my_kernel will be launched with
      int numThreads = 1;
      cudaDeviceProp deviceProp;
      cudaGetDeviceProperties(&deviceProp, dev);
      cudaOccupancyMaxActiveBlocksPerMultiprocessor(&numBlocksPerSm, test_launcher_kernel, numThreads, 0);
      cout << "number of blocks per SM " << numBlocksPerSm << endl;
      
      // launch
      void *kernelArgs[] = { &dBufferX, &dBufferY, &dBufferCounter, &host_function_ptr };

      int total_blocks = deviceProp.multiProcessorCount*numBlocksPerSm;
      while (total_blocks % 6 != 0) {
	total_blocks -= 1;
      }
      cout << "launching with blocks: " << total_blocks << endl;
      dim3 dimBlock(1, 1, 1);
      dim3 dimGrid(total_blocks, 1, 1);

      cudaLaunchCooperativeKernel((void *) test_launcher_kernel, dimGrid, dimBlock, kernelArgs);
      
      
      gpuErrchk(cudaMemcpy(hBufferCounter, dBufferCounter, sizeof(uint), cudaMemcpyDeviceToHost));
      assert(*hBufferCounter == total_blocks);
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
