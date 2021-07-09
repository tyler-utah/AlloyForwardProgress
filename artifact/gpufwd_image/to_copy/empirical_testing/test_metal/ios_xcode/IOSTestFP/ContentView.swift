//
//  ContentView.swift
//  TryingOut2
//
//  Created by Real Tyler Sorensen  on 12/10/20.
//
// Looking at: https://www.hackingwithswift.com/books/ios-swiftui/creating-a-form

import SwiftUI

// This seems like a good metal tutorial in swift
// https://gist.github.com/wakita/f4915757c6c6c128c05c8680cd859e1a#file-compute-metal
import MetalKit

//perform on the current thread
//dwi.perform()
//perpform on the global queue
//DispatchQueue.global().async(execute: dwi)
// Look here for dispatch docs:
// https://medium.com/@yostane/swift-sweet-bits-the-dispatch-framework-ios-10-e34451d59a86

struct ContentView: View {
    @State var tapCount = 0
    @State var computing = false
    @State var should_cancel = false
    @State var index = 0
    @State var test_log = "Test Log:"
    @State var action_log = "Action Log:"
    @State var local_i = 0;
    @State var inner_i = 0;
    @State var debug_i = 0;
    @State var killed_tests = 0;
    @State var elapsed_time = 0.0;
    let num_workgroups = 65532
    


    
    var body: some View {
        
        // nice resource to let the background thread update the UI:
        //https://stackoverflow.com/questions/26743367/updating-the-ui-using-dispatch-async-in-swift
        // Otherwise we get crazy errors
        Form {
            
            Button("Run Tests") {
                /*if computing {
                    return
                }
                if !computing {
                    computing = true
                }*/
                
               
                
                let dwi = DispatchWorkItem {
                    
                    let start = DispatchTime.now()
                    
                    // Metal setup (before tests) here:
                    let device = MTLCreateSystemDefaultDevice()
                    var to_print_errs = ""
                    var to_print_device = ""
                    if device == nil {
                        to_print_device = "Metal device is nil"
                    }
                    to_print_device = "\nusing device " +  (device?.name)!
                    
                    DispatchQueue.main.async {
                                // now update UI on main thread
                        action_log += to_print_device;
                    }
                    
                   
                    let library =  device?.makeDefaultLibrary()
                    if library == nil {
                        to_print_errs += "Could not create default library"
                    }
                    
                    DispatchQueue.main.async {
                                // now update UI on main thread
                        action_log += to_print_errs;
                    }
                    to_print_errs=""
                    
                    // Documented to be initialized to 0 https://developer.apple.com/documentation/metal/mtldevice/1433375-makebuffer
                    let XBuffer = device?.makeBuffer(length: num_workgroups * MemoryLayout<Int>.stride , options: [])!
                    
                    let YBuffer = device?.makeBuffer(length: num_workgroups * MemoryLayout<Int>.stride , options: [])!
                    
                    let resultBuffer = device?.makeBuffer(length: 1 * MemoryLayout<Int>.stride , options: [])!
                    
                    
                    
                    if (XBuffer == nil || YBuffer == nil || resultBuffer == nil )
                    {
                        to_print_errs = "\nError allocating buffers!"
                    }
                    to_print_errs=""
                    
                    DispatchQueue.main.async {
                                // now update UI on main thread
                        action_log += to_print_errs;
                    }
                    
                    // Metal setup end
                    
                    // For each test
                    var async_i = 0
                    while (async_i < test_names.count) {
                        
                        // Going backwards because the round robin ones are interesting here
                        let t_name = test_names[test_names.count - async_i - 1]
                        
                        DispatchQueue.main.async {
                                    // now update UI on main thread
                            test_log += "\nRunning Test: \(t_name)"
                            local_i = async_i
                        }
                        
                        
                        
                       
                        var killed = 0;
                        var success = 0;
                        
                        let test_kernel = library?.makeFunction(name: t_name)
                        if test_kernel == nil {
                          to_print_errs  += "\nCould not get kernel: " + t_name
                        }
                        
                        let XURP = XBuffer?.contents()
                        let YURP = YBuffer?.contents()
                      
                        let XHost = XURP?.bindMemory(to: Int.self, capacity: num_workgroups)
                      
                        let YHost = YURP?.bindMemory(to: Int.self, capacity: num_workgroups)

                        let resultURP = resultBuffer?.contents()
                        let resultHost = resultURP?.bindMemory(to: Int.self, capacity: 1)
                      
                        if (XURP == nil || YURP == nil || XHost == nil || YHost == nil || resultURP == nil || resultHost == nil ) {
                            to_print_errs += "\nError reinitializing memory!"
                        }
                        
                        DispatchQueue.main.async {
                                    // now update UI on main thread
                            action_log += to_print_errs
                        }
                        

                        let numThreadgroups = MTLSize(width: num_workgroups, height: 1, depth: 1)
                        let threadsPerThreadgroup = MTLSize(width: 1, height: 1, depth: 1)
                          

                        
                       for iter in 0...20 {
                         DispatchQueue.main.async {
                            // now update UI on main thread
                            inner_i = iter
                          }
                        
                            
                        
                          // This link seems to be okay for managing memory:
                          // https://developer.apple.com/forums/thread/67672
                          // initializing memory:
                            


                            XHost?.initialize(repeating: 0, count: num_workgroups)
                            YHost?.initialize(repeating: 0, count: num_workgroups)
                            resultHost?.initialize(repeating: 0, count: 1)
                        
                        let commandQueue = device?.makeCommandQueue()
                        if commandQueue == nil {
                            to_print_errs = "Command Queue is nil"
                        }

                            let commandBuffer = commandQueue?.makeCommandBuffer()!
                            if commandBuffer == nil {
                                to_print_errs += "CommandBuffer is nil"
                            }
                        
                          
                            let encoder = commandBuffer?.makeComputeCommandEncoder()!
                        
                            if encoder == nil {
                              to_print_errs += "\nencoder is nill"
                            }
                        
                           
                        
                          encoder?.setBuffer(XBuffer, offset: 0, index: 0)
                          encoder?.setBuffer(YBuffer, offset: 0, index: 1)
                          encoder?.setBuffer(resultBuffer, offset: 0, index: 2)

                        
                          
                        
                          do {
                            let pipeline_state = try device?.makeComputePipelineState(function: test_kernel!)
                            
                            if pipeline_state == nil {
                                to_print_errs += "\npipeline_state is  nil"
                            }
                            
                            encoder?.setComputePipelineState(pipeline_state!)
                            let _  = encoder?.dispatchThreadgroups(numThreadgroups, threadsPerThreadgroup: threadsPerThreadgroup)
                            
                            // This is important
                            encoder?.endEncoding()
                            
                            commandBuffer?.commit()
                            commandBuffer?.waitUntilCompleted()
                            let e = commandBuffer?.error
                            
                            if e == nil {
                                let result = resultBuffer?.contents().load(as: Int.self)
                                assert(result == num_workgroups)
                                //test_log += "\nStatus: finished"
                                success += 1;
                            }
                            else {
                                killed += 1;
                                //usleep(1000000/8)
                                //test_log += "\nStatus: KILLED\n\n"
                                //killed_tests += 1
                                /*DispatchQueue.main.async {
                                            // now update UI on main thread
                                    action_log += "Command buffer error: \(String(describing: commandBuffer?.error))"
                                    }*/
                                
                                //print("Command buffer error: \(String(describing: commandBuffer.error))")
                            }
                            
                            DispatchQueue.main.async {
                                        // now update UI on main thread
                                action_log += to_print_errs
                                }


                        }
                        catch {
                            to_print_errs += "setting the compute pipeline stage failed"
                        }
                        
                        
                        //usleep(1000000/16)
                        
                        
                        /*if should_cancel {
                            should_cancel = false
                            break
                          }*/
                        }
                        DispatchQueue.main.async {
                                    // now update UI on main thread
                            test_log += "\nFinished\nkilled: \(killed)\nSuccess: \(success)"
                            killed_tests += killed
                        }
                        
                        //
                        //killed_tests += killed
                        async_i += 1
                    }
                    computing = false
                    
                    // Timing code from:
                    // https://stackoverflow.com/questions/24755558/measure-elapsed-time-in-swift
                    let end = DispatchTime.now()
                    let nanoTime = end.uptimeNanoseconds - start.uptimeNanoseconds // <<<<< Difference in nano seconds (UInt64)
                    let timeInterval = Double(nanoTime) / 1_000_000_000 // Technically could overflow for long running tests

                    DispatchQueue.main.async {
                                // now update UI on main thread
                        elapsed_time = timeInterval
                    }
                        
                }
                
                //self.tapCount += 1
                //dwi.perform()
                DispatchQueue.global().async(execute: dwi)
            }
            
            Text("Ran \(local_i) tests out of \(test_names.count)\nLocal iterations: \(inner_i) \nKilled Tests: \(killed_tests)\nTime (seconds): \(elapsed_time)")
            Button("Cancel") {
                if !computing {
                    return
                }
                if should_cancel {
                    return
                }
                should_cancel=true
                
            }
            Button("Clear Test Log") {
                if computing {
                    return
                }
                if should_cancel {
                    return
                }
                test_log = "Test Log:"
                
            }
            
            // on how to get program data back https://stackoverflow.com/questions/38064042/access-files-in-var-mobile-containers-data-application-without-jailbreaking-iph
            Button("Save to File") {
                action_log += "\nSaving to file"
                if computing {
                    return
                }
                if should_cancel {
                    return
                }
               
                func getDocumentsDirectory() -> URL {
                    let paths = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)
                    return paths[0]
                }

                let filename = getDocumentsDirectory().appendingPathComponent("output.txt")

                do {
                    try test_log.write(to: filename, atomically: true, encoding: String.Encoding.utf8)
                } catch {
                    action_log += "\nFAILED TO WRITE TO FILE"
                    return
                }
                action_log += "\nWrote to file successfully: \(filename)"
                
            }
            Text(action_log).lineLimit(nil)
            Text(test_log).lineLimit(nil)
            
            
            
        }
        .navigationBarTitle(Text("Progress Tester"))
    }
}



struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

