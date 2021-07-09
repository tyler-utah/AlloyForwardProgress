//
//  main.m
//  TesterTemplate
//
//  Created by Real Tyler Sorensen  on 11/23/20.
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import "test_list.h"

#define INNER_ITERATIONS 20

int main(int argc, const char * argv[]) {
    @autoreleasepool {
  

        NSArray *kernels = get_kernels();


        NSDate *start_time = [NSDate date];
        
        // Sizes (update if running with bigger sizes)
        // assume workgroups_per_test divides total_workgroups
        //const unsigned int workgroups_per_test = 2;
        const unsigned int total_workgroups = 1;
        const unsigned int bufferSize = (total_workgroups * sizeof(int));
        const unsigned int num_threads = 3;
        
        
        
        // buffers
        id<MTLBuffer> BufferX;
        id<MTLBuffer> BufferY;
        id<MTLBuffer> BufferCounter;
        
        // boiler plate (copied from tutorials)
        //id<MTLDevice> device = MTLCreateSystemDefaultDevice();
        id<MTLDevice> device = MTLCopyAllDevices()[1];
        
        // allocating buffers
        BufferX = [device newBufferWithLength:bufferSize options:MTLResourceStorageModeShared];
        BufferY = [device newBufferWithLength:bufferSize options:MTLResourceStorageModeShared];
        BufferCounter = [device newBufferWithLength:bufferSize options:MTLResourceStorageModeShared];
        
        printf("using device: %s\n", [device.name UTF8String]);
        printf("total workgroups: %u\n", total_workgroups);
        //printf("workgroups per test: %u\n", workgroups_per_test);
        printf("buffer size: %u\n", bufferSize);
    
        id<MTLLibrary> defaultLibrary = [device newDefaultLibrary];
        if (defaultLibrary == nil) {
            printf("Failed to find the default library.");
            return -1;
        }
        
        // The command queue used to pass commands to the device.
        id<MTLCommandQueue> CommandQueue;
        CommandQueue = [device newCommandQueue];
        if (CommandQueue == nil) {
            printf("Failed to find the command queue.");
            return -1;
        }
        int total_killed = 0;
        int catch_up = 1;
        
        for (int test_id = 0; test_id < kernels.count; test_id++) {
        
            //char *test_name = "template test";
            NSString *test_name = kernels[test_id];
            if (![test_name containsString:@"plain"]) {
                continue;
            }
            if (catch_up) {
                if (![test_name isEqualToString:@"plain_2t_3i_14"]) {
                    printf("skipping test: %s\n", test_name.UTF8String);
                    continue;
                }
                else {
                    printf("skipping test: %s\n", test_name.UTF8String);
                    catch_up = 0;
                    continue;
                }
            }
            if ([test_name isEqualToString:@"plain_2t_3i_143"]) {
                printf("skipping BAD test: %s\n", test_name.UTF8String);
                continue;
            }
            
            printf("running test: %s\n", test_name.UTF8String);
            int success_count = 0, killed_count = 0;

            for (int inner_i = 0; inner_i < INNER_ITERATIONS; inner_i++) {
                //printf(".");
            
                // More boiler plate (copied in)
                NSError* error = nil;
        
                id<MTLComputePipelineState> testKernelPSO;
        
                // Load the shader files with a .metal file extension in the project
                id<MTLFunction> testKernel = [defaultLibrary newFunctionWithName:test_name];
                if (testKernel == nil) {
                    printf("Failed to find the test kernel function.");
                    return -1;
                }

                // Create a compute pipeline state object.
                testKernelPSO = [device newComputePipelineStateWithFunction: testKernel error:&error];
            
                if (testKernelPSO == nil) {
                    //  If the Metal API validation is enabled, you can find out more information about what
                    //  went wrong.  (Metal API validation is enabled by default when a debug build is run
                    //  from Xcode)
                    printf("Failed to created pipeline state object, error");
                    return -1;
                }
            


                // initializing buffers
                int * initX = BufferX.contents;
                int * initY = BufferY.contents;
                int * initCounter = BufferCounter.contents;
        
                initCounter[0] = 0;
                for (int i = 0; i < total_workgroups; i++) {
                    initX[i] = 0;
                    initY[i] = 0;
                }
        
                id<MTLCommandBuffer> commandBuffer = [CommandQueue commandBuffer];
                assert(commandBuffer != nil);

                // Start a compute pass.
                id<MTLComputeCommandEncoder> computeEncoder = [commandBuffer computeCommandEncoder];
                assert(computeEncoder != nil);

                // Encode the pipeline state object and its parameters.
                [computeEncoder setComputePipelineState:testKernelPSO];
                [computeEncoder setBuffer:BufferX offset:0 atIndex:0];
                [computeEncoder setBuffer:BufferY offset:0 atIndex:1];
                [computeEncoder setBuffer:BufferCounter offset:0 atIndex:2];
                
                MTLSize gridSize = MTLSizeMake(total_workgroups, 1, 1);
                MTLSize threadgroupSize = MTLSizeMake(num_threads, 1, 1);

                // Encode the compute command.
                [computeEncoder dispatchThreads:gridSize
                          threadsPerThreadgroup:threadgroupSize];

                // End the compute pass.
                [computeEncoder endEncoding];

                // Execute the command.
                [commandBuffer commit];
                    
                // Normally, you want to do other work in your app while the GPU is running,
                // but in this example, the code simply blocks until the calculation is complete.
                [commandBuffer waitUntilCompleted];
        
                // validate the results:
                initCounter = BufferCounter.contents;
                int success = (initCounter[0] == (total_workgroups*num_threads));
                if (success) {
                    printf(".");
                    success_count++;
                }
                else {
                    printf("x");
                    total_killed++;
                    killed_count++;
                }
                fflush(stdout);
            }
            printf("\nsuccess: %d\nkilled: %d\n", success_count, killed_count);
        }
        NSDate *end_time = [NSDate date];
        float seconds = [end_time timeIntervalSinceDate:start_time];
        printf("------\n");
        printf("finished\n");
        printf("tests ran: %d\n", kernels.count);
        printf("iterations per test: %d\n", INNER_ITERATIONS);
        printf("total tests killed: %d\n", total_killed);
        printf("total testing time (s): %f\n",seconds);
        
    }
    return 0;
}
