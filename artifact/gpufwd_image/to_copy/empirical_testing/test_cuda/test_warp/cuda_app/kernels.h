

__device__ void plain_2t_2i_0(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_2i_0_ptr = plain_2t_2i_0;
__device__ void plain_2t_2i_1(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_2i_1_ptr = plain_2t_2i_1;
__device__ void plain_2t_2i_2(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_2i_2_ptr = plain_2t_2i_2;
__device__ void plain_2t_2i_3(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_2i_3_ptr = plain_2t_2i_3;
__device__ void plain_2t_2i_4(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_2i_4_ptr = plain_2t_2i_4;
__device__ void plain_2t_2i_5(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_2i_5_ptr = plain_2t_2i_5;
__device__ void plain_2t_2i_6(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_2i_6_ptr = plain_2t_2i_6;
__device__ void plain_2t_2i_7(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_2i_7_ptr = plain_2t_2i_7;
__device__ void plain_2t_3i_0(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_0_ptr = plain_2t_3i_0;
__device__ void plain_2t_3i_1(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_1_ptr = plain_2t_3i_1;
__device__ void plain_2t_3i_2(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_2_ptr = plain_2t_3i_2;
__device__ void plain_2t_3i_3(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_3_ptr = plain_2t_3i_3;
__device__ void plain_2t_3i_4(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_4_ptr = plain_2t_3i_4;
__device__ void plain_2t_3i_5(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_5_ptr = plain_2t_3i_5;
__device__ void plain_2t_3i_6(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_6_ptr = plain_2t_3i_6;
__device__ void plain_2t_3i_7(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_7_ptr = plain_2t_3i_7;
__device__ void plain_2t_3i_8(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_8_ptr = plain_2t_3i_8;
__device__ void plain_2t_3i_9(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_9_ptr = plain_2t_3i_9;
__device__ void plain_2t_3i_10(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_10_ptr = plain_2t_3i_10;
__device__ void plain_2t_3i_11(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_11_ptr = plain_2t_3i_11;
__device__ void plain_2t_3i_12(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_12_ptr = plain_2t_3i_12;
__device__ void plain_2t_3i_13(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_13_ptr = plain_2t_3i_13;
__device__ void plain_2t_3i_14(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_14_ptr = plain_2t_3i_14;
__device__ void plain_2t_3i_15(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_15_ptr = plain_2t_3i_15;
__device__ void plain_2t_3i_16(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_16_ptr = plain_2t_3i_16;
__device__ void plain_2t_3i_17(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_17_ptr = plain_2t_3i_17;
__device__ void plain_2t_3i_18(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_18_ptr = plain_2t_3i_18;
__device__ void plain_2t_3i_19(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_19_ptr = plain_2t_3i_19;
__device__ void plain_2t_3i_20(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_20_ptr = plain_2t_3i_20;
__device__ void plain_2t_3i_21(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_21_ptr = plain_2t_3i_21;
__device__ void plain_2t_3i_22(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_22_ptr = plain_2t_3i_22;
__device__ void plain_2t_3i_23(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_23_ptr = plain_2t_3i_23;
__device__ void plain_2t_3i_24(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_24_ptr = plain_2t_3i_24;
__device__ void plain_2t_3i_25(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_25_ptr = plain_2t_3i_25;
__device__ void plain_2t_3i_26(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_26_ptr = plain_2t_3i_26;
__device__ void plain_2t_3i_27(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_27_ptr = plain_2t_3i_27;
__device__ void plain_2t_3i_28(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_28_ptr = plain_2t_3i_28;
__device__ void plain_2t_3i_29(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_29_ptr = plain_2t_3i_29;
__device__ void plain_2t_3i_30(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_30_ptr = plain_2t_3i_30;
__device__ void plain_2t_3i_31(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_31_ptr = plain_2t_3i_31;
__device__ void plain_2t_3i_32(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_32_ptr = plain_2t_3i_32;
__device__ void plain_2t_3i_33(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_33_ptr = plain_2t_3i_33;
__device__ void plain_2t_3i_34(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_34_ptr = plain_2t_3i_34;
__device__ void plain_2t_3i_35(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_35_ptr = plain_2t_3i_35;
__device__ void plain_2t_3i_36(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_36_ptr = plain_2t_3i_36;
__device__ void plain_2t_3i_37(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_37_ptr = plain_2t_3i_37;
__device__ void plain_2t_3i_38(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_38_ptr = plain_2t_3i_38;
__device__ void plain_2t_3i_39(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_39_ptr = plain_2t_3i_39;
__device__ void plain_2t_3i_40(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_40_ptr = plain_2t_3i_40;
__device__ void plain_2t_3i_41(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_41_ptr = plain_2t_3i_41;
__device__ void plain_2t_3i_42(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_42_ptr = plain_2t_3i_42;
__device__ void plain_2t_3i_43(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_43_ptr = plain_2t_3i_43;
__device__ void plain_2t_3i_44(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_44_ptr = plain_2t_3i_44;
__device__ void plain_2t_3i_45(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_45_ptr = plain_2t_3i_45;
__device__ void plain_2t_3i_46(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_46_ptr = plain_2t_3i_46;
__device__ void plain_2t_3i_47(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_47_ptr = plain_2t_3i_47;
__device__ void plain_2t_3i_48(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_48_ptr = plain_2t_3i_48;
__device__ void plain_2t_3i_49(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_49_ptr = plain_2t_3i_49;
__device__ void plain_2t_3i_50(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_50_ptr = plain_2t_3i_50;
__device__ void plain_2t_3i_51(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_51_ptr = plain_2t_3i_51;
__device__ void plain_2t_3i_52(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_52_ptr = plain_2t_3i_52;
__device__ void plain_2t_3i_53(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_53_ptr = plain_2t_3i_53;
__device__ void plain_2t_3i_54(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_54_ptr = plain_2t_3i_54;
__device__ void plain_2t_3i_55(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_55_ptr = plain_2t_3i_55;
__device__ void plain_2t_3i_56(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_56_ptr = plain_2t_3i_56;
__device__ void plain_2t_3i_57(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_57_ptr = plain_2t_3i_57;
__device__ void plain_2t_3i_58(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_58_ptr = plain_2t_3i_58;
__device__ void plain_2t_3i_59(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_59_ptr = plain_2t_3i_59;
__device__ void plain_2t_3i_60(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_60_ptr = plain_2t_3i_60;
__device__ void plain_2t_3i_61(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_61_ptr = plain_2t_3i_61;
__device__ void plain_2t_3i_62(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_62_ptr = plain_2t_3i_62;
__device__ void plain_2t_3i_63(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_63_ptr = plain_2t_3i_63;
__device__ void plain_2t_3i_64(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_64_ptr = plain_2t_3i_64;
__device__ void plain_2t_3i_65(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_65_ptr = plain_2t_3i_65;
__device__ void plain_2t_3i_66(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_66_ptr = plain_2t_3i_66;
__device__ void plain_2t_3i_67(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_67_ptr = plain_2t_3i_67;
__device__ void plain_2t_3i_68(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_68_ptr = plain_2t_3i_68;
__device__ void plain_2t_3i_69(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_69_ptr = plain_2t_3i_69;
__device__ void plain_2t_3i_70(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_70_ptr = plain_2t_3i_70;
__device__ void plain_2t_3i_71(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_71_ptr = plain_2t_3i_71;
__device__ void plain_2t_3i_72(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_72_ptr = plain_2t_3i_72;
__device__ void plain_2t_3i_73(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_73_ptr = plain_2t_3i_73;
__device__ void plain_2t_3i_74(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_74_ptr = plain_2t_3i_74;
__device__ void plain_2t_3i_75(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_75_ptr = plain_2t_3i_75;
__device__ void plain_2t_3i_76(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_76_ptr = plain_2t_3i_76;
__device__ void plain_2t_3i_77(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_77_ptr = plain_2t_3i_77;
__device__ void plain_2t_3i_78(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_78_ptr = plain_2t_3i_78;
__device__ void plain_2t_3i_79(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_79_ptr = plain_2t_3i_79;
__device__ void plain_2t_3i_80(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_80_ptr = plain_2t_3i_80;
__device__ void plain_2t_3i_81(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_81_ptr = plain_2t_3i_81;
__device__ void plain_2t_3i_82(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_82_ptr = plain_2t_3i_82;
__device__ void plain_2t_3i_83(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_83_ptr = plain_2t_3i_83;
__device__ void plain_2t_3i_84(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_84_ptr = plain_2t_3i_84;
__device__ void plain_2t_3i_85(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_85_ptr = plain_2t_3i_85;
__device__ void plain_2t_3i_86(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_86_ptr = plain_2t_3i_86;
__device__ void plain_2t_3i_87(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_87_ptr = plain_2t_3i_87;
__device__ void plain_2t_3i_88(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_88_ptr = plain_2t_3i_88;
__device__ void plain_2t_3i_89(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_89_ptr = plain_2t_3i_89;
__device__ void plain_2t_3i_90(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_90_ptr = plain_2t_3i_90;
__device__ void plain_2t_3i_91(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_91_ptr = plain_2t_3i_91;
__device__ void plain_2t_3i_92(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_92_ptr = plain_2t_3i_92;
__device__ void plain_2t_3i_93(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_93_ptr = plain_2t_3i_93;
__device__ void plain_2t_3i_94(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_94_ptr = plain_2t_3i_94;
__device__ void plain_2t_3i_95(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_95_ptr = plain_2t_3i_95;
__device__ void plain_2t_3i_96(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_96_ptr = plain_2t_3i_96;
__device__ void plain_2t_3i_97(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_97_ptr = plain_2t_3i_97;
__device__ void plain_2t_3i_98(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_98_ptr = plain_2t_3i_98;
__device__ void plain_2t_3i_99(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_99_ptr = plain_2t_3i_99;
__device__ void plain_2t_3i_100(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_100_ptr = plain_2t_3i_100;
__device__ void plain_2t_3i_101(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_101_ptr = plain_2t_3i_101;
__device__ void plain_2t_3i_102(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_102_ptr = plain_2t_3i_102;
__device__ void plain_2t_3i_103(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_103_ptr = plain_2t_3i_103;
__device__ void plain_2t_3i_104(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_104_ptr = plain_2t_3i_104;
__device__ void plain_2t_3i_105(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_105_ptr = plain_2t_3i_105;
__device__ void plain_2t_3i_106(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_106_ptr = plain_2t_3i_106;
__device__ void plain_2t_3i_107(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_107_ptr = plain_2t_3i_107;
__device__ void plain_2t_3i_108(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_108_ptr = plain_2t_3i_108;
__device__ void plain_2t_3i_109(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_109_ptr = plain_2t_3i_109;
__device__ void plain_2t_3i_110(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_110_ptr = plain_2t_3i_110;
__device__ void plain_2t_3i_111(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_111_ptr = plain_2t_3i_111;
__device__ void plain_2t_3i_112(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_112_ptr = plain_2t_3i_112;
__device__ void plain_2t_3i_113(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_113_ptr = plain_2t_3i_113;
__device__ void plain_2t_3i_114(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_114_ptr = plain_2t_3i_114;
__device__ void plain_2t_3i_115(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_115_ptr = plain_2t_3i_115;
__device__ void plain_2t_3i_116(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_116_ptr = plain_2t_3i_116;
__device__ void plain_2t_3i_117(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_117_ptr = plain_2t_3i_117;
__device__ void plain_2t_3i_118(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_118_ptr = plain_2t_3i_118;
__device__ void plain_2t_3i_119(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_119_ptr = plain_2t_3i_119;
__device__ void plain_2t_3i_120(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_120_ptr = plain_2t_3i_120;
__device__ void plain_2t_3i_121(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_121_ptr = plain_2t_3i_121;
__device__ void plain_2t_3i_122(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_122_ptr = plain_2t_3i_122;
__device__ void plain_2t_3i_123(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_123_ptr = plain_2t_3i_123;
__device__ void plain_2t_3i_124(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_124_ptr = plain_2t_3i_124;
__device__ void plain_2t_3i_125(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_125_ptr = plain_2t_3i_125;
__device__ void plain_2t_3i_126(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_126_ptr = plain_2t_3i_126;
__device__ void plain_2t_3i_127(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_127_ptr = plain_2t_3i_127;
__device__ void plain_2t_3i_128(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_128_ptr = plain_2t_3i_128;
__device__ void plain_2t_3i_129(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_129_ptr = plain_2t_3i_129;
__device__ void plain_2t_3i_130(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_130_ptr = plain_2t_3i_130;
__device__ void plain_2t_3i_131(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_131_ptr = plain_2t_3i_131;
__device__ void plain_2t_3i_132(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_132_ptr = plain_2t_3i_132;
__device__ void plain_2t_3i_133(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_133_ptr = plain_2t_3i_133;
__device__ void plain_2t_3i_134(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_134_ptr = plain_2t_3i_134;
__device__ void plain_2t_3i_135(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_135_ptr = plain_2t_3i_135;
__device__ void plain_2t_3i_136(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_136_ptr = plain_2t_3i_136;
__device__ void plain_2t_3i_137(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_137_ptr = plain_2t_3i_137;
__device__ void plain_2t_3i_138(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_138_ptr = plain_2t_3i_138;
__device__ void plain_2t_3i_139(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_139_ptr = plain_2t_3i_139;
__device__ void plain_2t_3i_140(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_140_ptr = plain_2t_3i_140;
__device__ void plain_2t_3i_141(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_141_ptr = plain_2t_3i_141;
__device__ void plain_2t_3i_142(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_142_ptr = plain_2t_3i_142;
__device__ void plain_2t_3i_143(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_143_ptr = plain_2t_3i_143;
__device__ void plain_2t_3i_144(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_144_ptr = plain_2t_3i_144;
__device__ void plain_2t_3i_145(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_145_ptr = plain_2t_3i_145;
__device__ void plain_2t_3i_146(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_146_ptr = plain_2t_3i_146;
__device__ void plain_2t_3i_147(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_147_ptr = plain_2t_3i_147;
__device__ void plain_2t_3i_148(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_148_ptr = plain_2t_3i_148;
__device__ void plain_2t_3i_149(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_149_ptr = plain_2t_3i_149;
__device__ void plain_2t_3i_150(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_150_ptr = plain_2t_3i_150;
__device__ void plain_2t_3i_151(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_151_ptr = plain_2t_3i_151;
__device__ void plain_2t_3i_152(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_152_ptr = plain_2t_3i_152;
__device__ void plain_2t_3i_153(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_153_ptr = plain_2t_3i_153;
__device__ void plain_2t_3i_154(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_154_ptr = plain_2t_3i_154;
__device__ void plain_2t_3i_155(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_155_ptr = plain_2t_3i_155;
__device__ void plain_2t_3i_156(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_156_ptr = plain_2t_3i_156;
__device__ void plain_2t_3i_157(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_157_ptr = plain_2t_3i_157;
__device__ void plain_2t_3i_158(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_158_ptr = plain_2t_3i_158;
__device__ void plain_2t_3i_159(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_159_ptr = plain_2t_3i_159;
__device__ void plain_2t_3i_160(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_160_ptr = plain_2t_3i_160;
__device__ void plain_2t_3i_161(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_161_ptr = plain_2t_3i_161;
__device__ void plain_2t_3i_162(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_162_ptr = plain_2t_3i_162;
__device__ void plain_2t_3i_163(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_163_ptr = plain_2t_3i_163;
__device__ void plain_2t_3i_164(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_164_ptr = plain_2t_3i_164;
__device__ void plain_2t_3i_165(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_165_ptr = plain_2t_3i_165;
__device__ void plain_2t_3i_166(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_166_ptr = plain_2t_3i_166;
__device__ void plain_2t_3i_167(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_167_ptr = plain_2t_3i_167;
__device__ void plain_2t_3i_168(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_168_ptr = plain_2t_3i_168;
__device__ void plain_2t_3i_169(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_169_ptr = plain_2t_3i_169;
__device__ void plain_2t_3i_170(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_170_ptr = plain_2t_3i_170;
__device__ void plain_2t_3i_171(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_171_ptr = plain_2t_3i_171;
__device__ void plain_2t_3i_172(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_172_ptr = plain_2t_3i_172;
__device__ void plain_2t_3i_173(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_173_ptr = plain_2t_3i_173;
__device__ void plain_2t_3i_174(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_174_ptr = plain_2t_3i_174;
__device__ void plain_2t_3i_175(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_3i_175_ptr = plain_2t_3i_175;
__device__ void plain_2t_4i_0(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_0_ptr = plain_2t_4i_0;
__device__ void plain_2t_4i_1(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_1_ptr = plain_2t_4i_1;
__device__ void plain_2t_4i_2(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_2_ptr = plain_2t_4i_2;
__device__ void plain_2t_4i_3(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_3_ptr = plain_2t_4i_3;
__device__ void plain_2t_4i_4(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_4_ptr = plain_2t_4i_4;
__device__ void plain_2t_4i_5(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_5_ptr = plain_2t_4i_5;
__device__ void plain_2t_4i_6(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_6_ptr = plain_2t_4i_6;
__device__ void plain_2t_4i_7(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_7_ptr = plain_2t_4i_7;
__device__ void plain_2t_4i_8(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_8_ptr = plain_2t_4i_8;
__device__ void plain_2t_4i_9(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_9_ptr = plain_2t_4i_9;
__device__ void plain_2t_4i_10(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_10_ptr = plain_2t_4i_10;
__device__ void plain_2t_4i_11(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_11_ptr = plain_2t_4i_11;
__device__ void plain_2t_4i_12(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_12_ptr = plain_2t_4i_12;
__device__ void plain_2t_4i_13(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_13_ptr = plain_2t_4i_13;
__device__ void plain_2t_4i_14(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_14_ptr = plain_2t_4i_14;
__device__ void plain_2t_4i_15(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_15_ptr = plain_2t_4i_15;
__device__ void plain_2t_4i_16(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_16_ptr = plain_2t_4i_16;
__device__ void plain_2t_4i_17(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_17_ptr = plain_2t_4i_17;
__device__ void plain_2t_4i_18(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_18_ptr = plain_2t_4i_18;
__device__ void plain_2t_4i_19(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_19_ptr = plain_2t_4i_19;
__device__ void plain_2t_4i_20(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_20_ptr = plain_2t_4i_20;
__device__ void plain_2t_4i_21(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_21_ptr = plain_2t_4i_21;
__device__ void plain_2t_4i_22(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_22_ptr = plain_2t_4i_22;
__device__ void plain_2t_4i_23(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_23_ptr = plain_2t_4i_23;
__device__ void plain_2t_4i_24(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_24_ptr = plain_2t_4i_24;
__device__ void plain_2t_4i_25(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_25_ptr = plain_2t_4i_25;
__device__ void plain_2t_4i_26(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_26_ptr = plain_2t_4i_26;
__device__ void plain_2t_4i_27(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_27_ptr = plain_2t_4i_27;
__device__ void plain_2t_4i_28(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_28_ptr = plain_2t_4i_28;
__device__ void plain_2t_4i_29(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_29_ptr = plain_2t_4i_29;
__device__ void plain_2t_4i_30(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_30_ptr = plain_2t_4i_30;
__device__ void plain_2t_4i_31(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_31_ptr = plain_2t_4i_31;
__device__ void plain_2t_4i_32(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_32_ptr = plain_2t_4i_32;
__device__ void plain_2t_4i_33(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_33_ptr = plain_2t_4i_33;
__device__ void plain_2t_4i_34(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_34_ptr = plain_2t_4i_34;
__device__ void plain_2t_4i_35(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_35_ptr = plain_2t_4i_35;
__device__ void plain_2t_4i_36(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_36_ptr = plain_2t_4i_36;
__device__ void plain_2t_4i_37(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_37_ptr = plain_2t_4i_37;
__device__ void plain_2t_4i_38(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_38_ptr = plain_2t_4i_38;
__device__ void plain_2t_4i_39(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_39_ptr = plain_2t_4i_39;
__device__ void plain_2t_4i_40(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_40_ptr = plain_2t_4i_40;
__device__ void plain_2t_4i_41(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_41_ptr = plain_2t_4i_41;
__device__ void plain_2t_4i_42(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_42_ptr = plain_2t_4i_42;
__device__ void plain_2t_4i_43(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_43_ptr = plain_2t_4i_43;
__device__ void plain_2t_4i_44(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_44_ptr = plain_2t_4i_44;
__device__ void plain_2t_4i_45(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_45_ptr = plain_2t_4i_45;
__device__ void plain_2t_4i_46(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_46_ptr = plain_2t_4i_46;
__device__ void plain_2t_4i_47(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_47_ptr = plain_2t_4i_47;
__device__ void plain_2t_4i_48(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_48_ptr = plain_2t_4i_48;
__device__ void plain_2t_4i_49(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_49_ptr = plain_2t_4i_49;
__device__ void plain_2t_4i_50(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_50_ptr = plain_2t_4i_50;
__device__ void plain_2t_4i_51(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_51_ptr = plain_2t_4i_51;
__device__ void plain_2t_4i_52(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_52_ptr = plain_2t_4i_52;
__device__ void plain_2t_4i_53(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_53_ptr = plain_2t_4i_53;
__device__ void plain_2t_4i_54(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_54_ptr = plain_2t_4i_54;
__device__ void plain_2t_4i_55(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_55_ptr = plain_2t_4i_55;
__device__ void plain_2t_4i_56(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_56_ptr = plain_2t_4i_56;
__device__ void plain_2t_4i_57(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_57_ptr = plain_2t_4i_57;
__device__ void plain_2t_4i_58(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_58_ptr = plain_2t_4i_58;
__device__ void plain_2t_4i_59(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_59_ptr = plain_2t_4i_59;
__device__ void plain_2t_4i_60(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_60_ptr = plain_2t_4i_60;
__device__ void plain_2t_4i_61(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_61_ptr = plain_2t_4i_61;
__device__ void plain_2t_4i_62(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_62_ptr = plain_2t_4i_62;
__device__ void plain_2t_4i_63(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_63_ptr = plain_2t_4i_63;
__device__ void plain_2t_4i_64(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_64_ptr = plain_2t_4i_64;
__device__ void plain_2t_4i_65(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_65_ptr = plain_2t_4i_65;
__device__ void plain_2t_4i_66(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_66_ptr = plain_2t_4i_66;
__device__ void plain_2t_4i_67(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_67_ptr = plain_2t_4i_67;
__device__ void plain_2t_4i_68(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_68_ptr = plain_2t_4i_68;
__device__ void plain_2t_4i_69(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_69_ptr = plain_2t_4i_69;
__device__ void plain_2t_4i_70(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_70_ptr = plain_2t_4i_70;
__device__ void plain_2t_4i_71(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_71_ptr = plain_2t_4i_71;
__device__ void plain_2t_4i_72(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_72_ptr = plain_2t_4i_72;
__device__ void plain_2t_4i_73(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_73_ptr = plain_2t_4i_73;
__device__ void plain_2t_4i_74(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_74_ptr = plain_2t_4i_74;
__device__ void plain_2t_4i_75(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_75_ptr = plain_2t_4i_75;
__device__ void plain_2t_4i_76(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_76_ptr = plain_2t_4i_76;
__device__ void plain_2t_4i_77(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_77_ptr = plain_2t_4i_77;
__device__ void plain_2t_4i_78(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_78_ptr = plain_2t_4i_78;
__device__ void plain_2t_4i_79(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_79_ptr = plain_2t_4i_79;
__device__ void plain_2t_4i_80(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_80_ptr = plain_2t_4i_80;
__device__ void plain_2t_4i_81(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_81_ptr = plain_2t_4i_81;
__device__ void plain_2t_4i_82(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_82_ptr = plain_2t_4i_82;
__device__ void plain_2t_4i_83(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_83_ptr = plain_2t_4i_83;
__device__ void plain_2t_4i_84(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_84_ptr = plain_2t_4i_84;
__device__ void plain_2t_4i_85(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_85_ptr = plain_2t_4i_85;
__device__ void plain_2t_4i_86(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_86_ptr = plain_2t_4i_86;
__device__ void plain_2t_4i_87(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_87_ptr = plain_2t_4i_87;
__device__ void plain_2t_4i_88(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_88_ptr = plain_2t_4i_88;
__device__ void plain_2t_4i_89(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_89_ptr = plain_2t_4i_89;
__device__ void plain_2t_4i_90(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_90_ptr = plain_2t_4i_90;
__device__ void plain_2t_4i_91(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_91_ptr = plain_2t_4i_91;
__device__ void plain_2t_4i_92(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_92_ptr = plain_2t_4i_92;
__device__ void plain_2t_4i_93(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_93_ptr = plain_2t_4i_93;
__device__ void plain_2t_4i_94(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_94_ptr = plain_2t_4i_94;
__device__ void plain_2t_4i_95(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_95_ptr = plain_2t_4i_95;
__device__ void plain_2t_4i_96(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_96_ptr = plain_2t_4i_96;
__device__ void plain_2t_4i_97(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_97_ptr = plain_2t_4i_97;
__device__ void plain_2t_4i_98(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_98_ptr = plain_2t_4i_98;
__device__ void plain_2t_4i_99(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_99_ptr = plain_2t_4i_99;
__device__ void plain_2t_4i_100(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_100_ptr = plain_2t_4i_100;
__device__ void plain_2t_4i_101(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_101_ptr = plain_2t_4i_101;
__device__ void plain_2t_4i_102(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_102_ptr = plain_2t_4i_102;
__device__ void plain_2t_4i_103(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_103_ptr = plain_2t_4i_103;
__device__ void plain_2t_4i_104(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_104_ptr = plain_2t_4i_104;
__device__ void plain_2t_4i_105(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_105_ptr = plain_2t_4i_105;
__device__ void plain_2t_4i_106(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(y,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(y,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_106_ptr = plain_2t_4i_106;
__device__ void plain_2t_4i_107(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(y,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(y,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_107_ptr = plain_2t_4i_107;
__device__ void plain_2t_4i_108(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_108_ptr = plain_2t_4i_108;
__device__ void plain_2t_4i_109(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_109_ptr = plain_2t_4i_109;
__device__ void plain_2t_4i_110(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_110_ptr = plain_2t_4i_110;
__device__ void plain_2t_4i_111(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_111_ptr = plain_2t_4i_111;
__device__ void plain_2t_4i_112(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_112_ptr = plain_2t_4i_112;
__device__ void plain_2t_4i_113(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_113_ptr = plain_2t_4i_113;
__device__ void plain_2t_4i_114(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_114_ptr = plain_2t_4i_114;
__device__ void plain_2t_4i_115(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_115_ptr = plain_2t_4i_115;
__device__ void plain_2t_4i_116(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_116_ptr = plain_2t_4i_116;
__device__ void plain_2t_4i_117(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_117_ptr = plain_2t_4i_117;
__device__ void plain_2t_4i_118(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_118_ptr = plain_2t_4i_118;
__device__ void plain_2t_4i_119(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_119_ptr = plain_2t_4i_119;
__device__ void plain_2t_4i_120(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_120_ptr = plain_2t_4i_120;
__device__ void plain_2t_4i_121(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_121_ptr = plain_2t_4i_121;
__device__ void plain_2t_4i_122(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_122_ptr = plain_2t_4i_122;
__device__ void plain_2t_4i_123(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_123_ptr = plain_2t_4i_123;
__device__ void plain_2t_4i_124(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_124_ptr = plain_2t_4i_124;
__device__ void plain_2t_4i_125(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_125_ptr = plain_2t_4i_125;
__device__ void plain_2t_4i_126(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_126_ptr = plain_2t_4i_126;
__device__ void plain_2t_4i_127(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_127_ptr = plain_2t_4i_127;
__device__ void plain_2t_4i_128(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_128_ptr = plain_2t_4i_128;
__device__ void plain_2t_4i_129(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_129_ptr = plain_2t_4i_129;
__device__ void plain_2t_4i_130(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_130_ptr = plain_2t_4i_130;
__device__ void plain_2t_4i_131(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_131_ptr = plain_2t_4i_131;
__device__ void plain_2t_4i_132(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_132_ptr = plain_2t_4i_132;
__device__ void plain_2t_4i_133(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_133_ptr = plain_2t_4i_133;
__device__ void plain_2t_4i_134(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_134_ptr = plain_2t_4i_134;
__device__ void plain_2t_4i_135(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_135_ptr = plain_2t_4i_135;
__device__ void plain_2t_4i_136(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_136_ptr = plain_2t_4i_136;
__device__ void plain_2t_4i_137(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_137_ptr = plain_2t_4i_137;
__device__ void plain_2t_4i_138(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_138_ptr = plain_2t_4i_138;
__device__ void plain_2t_4i_139(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_139_ptr = plain_2t_4i_139;
__device__ void plain_2t_4i_140(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_140_ptr = plain_2t_4i_140;
__device__ void plain_2t_4i_141(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_141_ptr = plain_2t_4i_141;
__device__ void plain_2t_4i_142(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_142_ptr = plain_2t_4i_142;
__device__ void plain_2t_4i_143(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_143_ptr = plain_2t_4i_143;
__device__ void plain_2t_4i_144(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_144_ptr = plain_2t_4i_144;
__device__ void plain_2t_4i_145(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_145_ptr = plain_2t_4i_145;
__device__ void plain_2t_4i_146(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_146_ptr = plain_2t_4i_146;
__device__ void plain_2t_4i_147(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_147_ptr = plain_2t_4i_147;
__device__ void plain_2t_4i_148(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_148_ptr = plain_2t_4i_148;
__device__ void plain_2t_4i_149(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_149_ptr = plain_2t_4i_149;
__device__ void plain_2t_4i_150(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_150_ptr = plain_2t_4i_150;
__device__ void plain_2t_4i_151(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_151_ptr = plain_2t_4i_151;
__device__ void plain_2t_4i_152(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_152_ptr = plain_2t_4i_152;
__device__ void plain_2t_4i_153(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_153_ptr = plain_2t_4i_153;
__device__ void plain_2t_4i_154(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(y,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(y,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_154_ptr = plain_2t_4i_154;
__device__ void plain_2t_4i_155(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(y,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(y,0) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_155_ptr = plain_2t_4i_155;
__device__ void plain_2t_4i_156(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_156_ptr = plain_2t_4i_156;
__device__ void plain_2t_4i_157(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_157_ptr = plain_2t_4i_157;
__device__ void plain_2t_4i_158(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_158_ptr = plain_2t_4i_158;
__device__ void plain_2t_4i_159(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_159_ptr = plain_2t_4i_159;
__device__ void plain_2t_4i_160(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_160_ptr = plain_2t_4i_160;
__device__ void plain_2t_4i_161(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_161_ptr = plain_2t_4i_161;
__device__ void plain_2t_4i_162(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_162_ptr = plain_2t_4i_162;
__device__ void plain_2t_4i_163(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_163_ptr = plain_2t_4i_163;
__device__ void plain_2t_4i_164(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_164_ptr = plain_2t_4i_164;
__device__ void plain_2t_4i_165(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_165_ptr = plain_2t_4i_165;
__device__ void plain_2t_4i_166(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_166_ptr = plain_2t_4i_166;
__device__ void plain_2t_4i_167(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 3;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_167_ptr = plain_2t_4i_167;
__device__ void plain_2t_4i_168(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_168_ptr = plain_2t_4i_168;
__device__ void plain_2t_4i_169(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_169_ptr = plain_2t_4i_169;
__device__ void plain_2t_4i_170(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_170_ptr = plain_2t_4i_170;
__device__ void plain_2t_4i_171(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_171_ptr = plain_2t_4i_171;
__device__ void plain_2t_4i_172(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,0);
		pc = pc + 1;
		break;

	  case 2: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 3:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_2t_4i_172_ptr = plain_2t_4i_172;
__device__ void plain_3t_3i_0(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_0_ptr = plain_3t_3i_0;
__device__ void plain_3t_3i_1(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_1_ptr = plain_3t_3i_1;
__device__ void plain_3t_3i_2(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_2_ptr = plain_3t_3i_2;
__device__ void plain_3t_3i_3(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_3_ptr = plain_3t_3i_3;
__device__ void plain_3t_3i_4(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_4_ptr = plain_3t_3i_4;
__device__ void plain_3t_3i_5(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_5_ptr = plain_3t_3i_5;
__device__ void plain_3t_3i_6(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_6_ptr = plain_3t_3i_6;
__device__ void plain_3t_3i_7(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_7_ptr = plain_3t_3i_7;
__device__ void plain_3t_3i_8(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_8_ptr = plain_3t_3i_8;
__device__ void plain_3t_3i_9(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_9_ptr = plain_3t_3i_9;
__device__ void plain_3t_3i_10(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_10_ptr = plain_3t_3i_10;
__device__ void plain_3t_3i_11(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_11_ptr = plain_3t_3i_11;
__device__ void plain_3t_3i_12(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_12_ptr = plain_3t_3i_12;
__device__ void plain_3t_3i_13(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_13_ptr = plain_3t_3i_13;
__device__ void plain_3t_3i_14(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_14_ptr = plain_3t_3i_14;
__device__ void plain_3t_3i_15(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_15_ptr = plain_3t_3i_15;
__device__ void plain_3t_3i_16(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_16_ptr = plain_3t_3i_16;
__device__ void plain_3t_3i_17(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_17_ptr = plain_3t_3i_17;
__device__ void plain_3t_3i_18(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_18_ptr = plain_3t_3i_18;
__device__ void plain_3t_3i_19(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_19_ptr = plain_3t_3i_19;
__device__ void plain_3t_3i_20(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_3i_20_ptr = plain_3t_3i_20;
__device__ void plain_3t_4i_0(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_0_ptr = plain_3t_4i_0;
__device__ void plain_3t_4i_1(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_1_ptr = plain_3t_4i_1;
__device__ void plain_3t_4i_2(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_2_ptr = plain_3t_4i_2;
__device__ void plain_3t_4i_3(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_3_ptr = plain_3t_4i_3;
__device__ void plain_3t_4i_4(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_4_ptr = plain_3t_4i_4;
__device__ void plain_3t_4i_5(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_5_ptr = plain_3t_4i_5;
__device__ void plain_3t_4i_6(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_6_ptr = plain_3t_4i_6;
__device__ void plain_3t_4i_7(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_7_ptr = plain_3t_4i_7;
__device__ void plain_3t_4i_8(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_8_ptr = plain_3t_4i_8;
__device__ void plain_3t_4i_9(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_9_ptr = plain_3t_4i_9;
__device__ void plain_3t_4i_10(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_10_ptr = plain_3t_4i_10;
__device__ void plain_3t_4i_11(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_11_ptr = plain_3t_4i_11;
__device__ void plain_3t_4i_12(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_12_ptr = plain_3t_4i_12;
__device__ void plain_3t_4i_13(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_13_ptr = plain_3t_4i_13;
__device__ void plain_3t_4i_14(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_14_ptr = plain_3t_4i_14;
__device__ void plain_3t_4i_15(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_15_ptr = plain_3t_4i_15;
__device__ void plain_3t_4i_16(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_16_ptr = plain_3t_4i_16;
__device__ void plain_3t_4i_17(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_17_ptr = plain_3t_4i_17;
__device__ void plain_3t_4i_18(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_18_ptr = plain_3t_4i_18;
__device__ void plain_3t_4i_19(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_19_ptr = plain_3t_4i_19;
__device__ void plain_3t_4i_20(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_20_ptr = plain_3t_4i_20;
__device__ void plain_3t_4i_21(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_21_ptr = plain_3t_4i_21;
__device__ void plain_3t_4i_22(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_22_ptr = plain_3t_4i_22;
__device__ void plain_3t_4i_23(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_23_ptr = plain_3t_4i_23;
__device__ void plain_3t_4i_24(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_24_ptr = plain_3t_4i_24;
__device__ void plain_3t_4i_25(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_25_ptr = plain_3t_4i_25;
__device__ void plain_3t_4i_26(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 0) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_26_ptr = plain_3t_4i_26;
__device__ void plain_3t_4i_27(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_27_ptr = plain_3t_4i_27;
__device__ void plain_3t_4i_28(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_28_ptr = plain_3t_4i_28;
__device__ void plain_3t_4i_29(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_29_ptr = plain_3t_4i_29;
__device__ void plain_3t_4i_30(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_30_ptr = plain_3t_4i_30;
__device__ void plain_3t_4i_31(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_31_ptr = plain_3t_4i_31;
__device__ void plain_3t_4i_32(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_32_ptr = plain_3t_4i_32;
__device__ void plain_3t_4i_33(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_33_ptr = plain_3t_4i_33;
__device__ void plain_3t_4i_34(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_34_ptr = plain_3t_4i_34;
__device__ void plain_3t_4i_35(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_35_ptr = plain_3t_4i_35;
__device__ void plain_3t_4i_36(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_36_ptr = plain_3t_4i_36;
__device__ void plain_3t_4i_37(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_37_ptr = plain_3t_4i_37;
__device__ void plain_3t_4i_38(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,0) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_38_ptr = plain_3t_4i_38;
__device__ void plain_3t_4i_39(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_39_ptr = plain_3t_4i_39;
__device__ void plain_3t_4i_40(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_40_ptr = plain_3t_4i_40;
__device__ void plain_3t_4i_41(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_41_ptr = plain_3t_4i_41;
__device__ void plain_3t_4i_42(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_42_ptr = plain_3t_4i_42;
__device__ void plain_3t_4i_43(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_43_ptr = plain_3t_4i_43;
__device__ void plain_3t_4i_44(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_44_ptr = plain_3t_4i_44;
__device__ void plain_3t_4i_45(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_45_ptr = plain_3t_4i_45;
__device__ void plain_3t_4i_46(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_46_ptr = plain_3t_4i_46;
__device__ void plain_3t_4i_47(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_47_ptr = plain_3t_4i_47;
__device__ void plain_3t_4i_48(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_48_ptr = plain_3t_4i_48;
__device__ void plain_3t_4i_49(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_49_ptr = plain_3t_4i_49;
__device__ void plain_3t_4i_50(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_50_ptr = plain_3t_4i_50;
__device__ void plain_3t_4i_51(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_51_ptr = plain_3t_4i_51;
__device__ void plain_3t_4i_52(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_52_ptr = plain_3t_4i_52;
__device__ void plain_3t_4i_53(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_53_ptr = plain_3t_4i_53;
__device__ void plain_3t_4i_54(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_54_ptr = plain_3t_4i_54;
__device__ void plain_3t_4i_55(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_55_ptr = plain_3t_4i_55;
__device__ void plain_3t_4i_56(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_56_ptr = plain_3t_4i_56;
__device__ void plain_3t_4i_57(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_57_ptr = plain_3t_4i_57;
__device__ void plain_3t_4i_58(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_58_ptr = plain_3t_4i_58;
__device__ void plain_3t_4i_59(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_59_ptr = plain_3t_4i_59;
__device__ void plain_3t_4i_60(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_60_ptr = plain_3t_4i_60;
__device__ void plain_3t_4i_61(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_61_ptr = plain_3t_4i_61;
__device__ void plain_3t_4i_62(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(x, 0) == 1 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_62_ptr = plain_3t_4i_62;
__device__ void plain_3t_4i_63(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_63_ptr = plain_3t_4i_63;
__device__ void plain_3t_4i_64(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_64_ptr = plain_3t_4i_64;
__device__ void plain_3t_4i_65(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_65_ptr = plain_3t_4i_65;
__device__ void plain_3t_4i_66(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_66_ptr = plain_3t_4i_66;
__device__ void plain_3t_4i_67(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_67_ptr = plain_3t_4i_67;
__device__ void plain_3t_4i_68(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,1) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_68_ptr = plain_3t_4i_68;
__device__ void plain_3t_4i_69(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_69_ptr = plain_3t_4i_69;
__device__ void plain_3t_4i_70(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_70_ptr = plain_3t_4i_70;
__device__ void plain_3t_4i_71(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_71_ptr = plain_3t_4i_71;
__device__ void plain_3t_4i_72(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_72_ptr = plain_3t_4i_72;
__device__ void plain_3t_4i_73(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_73_ptr = plain_3t_4i_73;
__device__ void plain_3t_4i_74(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_74_ptr = plain_3t_4i_74;
__device__ void plain_3t_4i_75(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_75_ptr = plain_3t_4i_75;
__device__ void plain_3t_4i_76(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_76_ptr = plain_3t_4i_76;
__device__ void plain_3t_4i_77(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_77_ptr = plain_3t_4i_77;
__device__ void plain_3t_4i_78(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_78_ptr = plain_3t_4i_78;
__device__ void plain_3t_4i_79(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_79_ptr = plain_3t_4i_79;
__device__ void plain_3t_4i_80(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_80_ptr = plain_3t_4i_80;
__device__ void plain_3t_4i_81(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_81_ptr = plain_3t_4i_81;
__device__ void plain_3t_4i_82(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_82_ptr = plain_3t_4i_82;
__device__ void plain_3t_4i_83(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_83_ptr = plain_3t_4i_83;
__device__ void plain_3t_4i_84(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicExch(x,1) == 1) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_84_ptr = plain_3t_4i_84;
__device__ void plain_3t_4i_85(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_85_ptr = plain_3t_4i_85;
__device__ void plain_3t_4i_86(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_86_ptr = plain_3t_4i_86;
__device__ void plain_3t_4i_87(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_87_ptr = plain_3t_4i_87;
__device__ void plain_3t_4i_88(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_88_ptr = plain_3t_4i_88;
__device__ void plain_3t_4i_89(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_89_ptr = plain_3t_4i_89;
__device__ void plain_3t_4i_90(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_90_ptr = plain_3t_4i_90;
__device__ void plain_3t_4i_91(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_91_ptr = plain_3t_4i_91;
__device__ void plain_3t_4i_92(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_92_ptr = plain_3t_4i_92;
__device__ void plain_3t_4i_93(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_93_ptr = plain_3t_4i_93;
__device__ void plain_3t_4i_94(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_94_ptr = plain_3t_4i_94;
__device__ void plain_3t_4i_95(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_95_ptr = plain_3t_4i_95;
__device__ void plain_3t_4i_96(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_96_ptr = plain_3t_4i_96;
__device__ void plain_3t_4i_97(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_97_ptr = plain_3t_4i_97;
__device__ void plain_3t_4i_98(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicExch(x,0) == 0) { 
		   pc = 2;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_98_ptr = plain_3t_4i_98;
__device__ void plain_3t_4i_99(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_99_ptr = plain_3t_4i_99;
__device__ void plain_3t_4i_100(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_100_ptr = plain_3t_4i_100;
__device__ void plain_3t_4i_101(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_101_ptr = plain_3t_4i_101;
__device__ void plain_3t_4i_102(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_102_ptr = plain_3t_4i_102;
__device__ void plain_3t_4i_103(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_103_ptr = plain_3t_4i_103;
__device__ void plain_3t_4i_104(uint * x, uint * y, uint* count) {
	int pc = 0;
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int total_num_threads = gridDim.x * blockDim.x;

	if (tid == 0) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(x,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 1) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		if (atomicAdd(x, 0) == 0 ) { 
		   pc = 0;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 1: 
		if (atomicAdd(y, 0) == 0 ) { 
		   pc = 1;
		}
		else {
		   pc = pc + 1;
		}
		break;

	  case 2:
		terminate = 1;
		break;

	     }
	   }
	}

	if (tid == 2) { 
	   int terminate = 0;

	while (true) {
	   if (terminate == 1) {
	   break;
	}
	switch(pc) {

	  case 0: 
		atomicExch(y,1);
		pc = pc + 1;
		break;

	  case 1:
		terminate = 1;
		break;

	     }
	   }
	}

	atomicAdd(count, 1);
}
__device__ tfunc plain_3t_4i_104_ptr = plain_3t_4i_104;
