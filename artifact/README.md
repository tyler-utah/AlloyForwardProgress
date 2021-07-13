# Artifact for "Specifying and Testing GPU Workgroup Progress Models"

## Abstract

This is the OOPSLA '21 artifact for the paper "Specifying and Testing GPU Workgroup Progress Models". We assume that the user has read the paper, and this documentation will refer to the paper (and use notation from the paper) throughout. 

If you have read the paper, you will notice that we test a diversity of devices, from iPhones, to iPads, to Android tablets. It is thus not feasible for us to provide the ability to reproduce the results of the paper exactly, which would require access to a suitable array of devices. We provide the means to reproduce all aspects of the work that do not require specific devices, and we include instructions for running tests on GPU devices if they are available. Also, we have included the ability to run our experiments on a software-emulated GPU called [Swift Shader](https://github.com/google/swiftshader). Furthermore, we include all data from running our experiments across a diversity of devices.

One of the formal tools we use, [CADP](https://en.wikipedia.org/wiki/Construction_and_Analysis_of_Distributed_Processes), requires a non-standard license to run. An academic licenses for CADP can be acquired easily and free of charge by filling out a simple email form; however, we could not legally bundle the source (or an executable) of this tool. We hope the evaluators will follow our simple rules for obtaining the tool to run this section of experiments.

Because our synthesis results required over 1 month of execution time on a high-end server, we have included scripts to run a representative subset of synthesis experiments.

## Getting started

These instructions have been tested on a 64-bit Linux machine running an OS
similar to Ubuntu 18.04 with Docker installed and with Bash as the shell. Most of our software is included in the docker image. All data and most software required for the artifact is also included in this repository in the `to_copy` directory.

## Accessing the docker image

The artifact contains the necessary data and scripts to build a docker container; however, this can be a lengthy process. For convenience, the `gpufwd-image.tar` file is a pre-built docker image.

To launch the docker image, please run:

```
sudo docker load --input gpufwd-image.tar
sudo docker stop gpufwd-container  # Will fail if no such container is running; that's OK
sudo docker rm gpufwd-container    # Will fail if there is no such container; that's OK
sudo docker create -it --name gpufwd-container gpufwd-image
sudo docker start -ia gpufwd-container
```

## Build the docker image

(this step is unnecessary if you have obtained the prebuilt docker image from the previous step)

Change into the directory:

```sh
cd gpufwd_image/
```

Execute the following commands to build the Docker image, 
build the Docker container, and start the Docker container:

```sh
sudo docker build -t gpufwd-image .

sudo docker stop gpufwd-container  # Will fail if no such container is running; that's OK
sudo docker rm gpufwd-container    # Will fail if there is no such container; that's OK
sudo docker create -it --name gpufwd-container gpufwd-image

sudo docker start -ia gpufwd-container
```

You should now have a Bash shell inside the container.

## Test Generation

We begin by discussing the test synthesis process described in Section 5 "Automatic Synthesis of Progress Litmus Tests". This component requires a slightly modified version of the [Alloy](https://alloytools.org/) relational model checker, which we have included in this repo, copied into the docker and built.

To run these experiments, change into the `/data/test_synthesis/alloy5` directory. The formal model describing the LTS and semantics of our simple programming language can be found in `progress.als`.

Recall from the paper, that there are 5 different test configurations, which vary the number of threads and instructions in the synthesis run. Recall that all configurations except for the smallest configuation (2 threads and 2 instructions) timed out, running for approximately 1 week on a very large server (i.e. with 1 TB of main memory). We appreciate that this may be too long and too large of a machine for the reviews, thus we suggest the reviews run only the smallest configuration.

To do this, we have provided the simple `to_run.sh` bash script in this directory. This script shows the 5 commands to run the 5 configurations described in the paper. Please note the values for each of the calls, which vary the number of components to run the synthesis, including the number of threads and instructions. We have commented all lines except for the smallest configuration; this command should execute in several minutes on a moderately sized server. 

Upon launching the `to_run.sh` script, the user will see a stream of two characters. The `x` character means that a unique test was found. On the other hand, a `.` character means that a redundant test was found. The synthesis should complete showing 6 unique tests were found, and a large number of total tests (most of which are redundant, as described in Section 5 of the paper). The unique tests can be observed in the directory `../out/2t_2i`. There is an integer number describing each test (0-5 inclusive). 

Each test directory will contain several files: the `.xml` and `.dot` files are generated by Alloy. The `.txt` files are produced by our simple post processing to create a pseudo-code representation of each test. The `_simple.txt` file performs some additional syntax sugar to the tests to make them even easier to read.

Feel free to play with some of the other 4 commands in `to_run.sh`. We do not recommend running the commands for the full week that we did, but you should be able to observe some of the `.` and `x` characters start to stream to the screen.


## CADP: model-checking test termination

In Section 4 "Executable Semantics of Progress Models", we describe how we use
the CADP verification toolbox to automatically check whether a given litmus test
is guaranteed to terminate under various progress models. Here we describe how
to install CADP, and how to run our scripts that use CADP to do the
verification.

### CADP install

CADP is a closed-source research software that requires a license to run, and as
such it was not possible for us to embed it in this artifact.

To install CADP and get a license, see:
https://cadp.inria.fr/registration/

Academic users can obtain a personal, free-of-charge license.

Our experiments are known to work with CADP version `2020-l`, please make sure
to install this version.

For users who cannot easily obtain CADP, we still provide a standalone example
that shows CADP input and output files, to illustrate how we use the toolbox and
how it lets us check for test termination.

### Standalone example: mutex litmus test

We use the article's running example of two threads competing for a mutex as a
standalone example.

We have two types of input files to CADP:

 - `*.lnt` files represent models written in the LNT formal language.
 
 - `*.svl` files represent verification scenarios written in the script
   verification language (SVL), where we typically check properties expressed in
   the model checking language (MCL) on some model written in LNT.

The `cadp/mutex-standalone-example/` directory contains the following files.

`mutex.lnt` is the LNT model of our mutex example. In this file we find the
definition of the various types and processes needed to express our litmus
tests, including the definition of the progress models. These LNT sources are
the basis for the LNT listings of the article, where they are only slightly
edited to be shorter and remove small and irrelevant implementation details.

Most of the code of `mutex.lnt` is generic, only the AXB instructions given in
argument to the INTERPRETER processes are specific to the mutex example. For the
sake of simplicity in this standalone example, we decided to keep everything in
a single file containing both generic code and the mutex-specific AXB programs.

`verif.svl` contains the SVL verification script with the MCL formulas used to
check deadlocks under both weak and strong fairness, as discussed in the
article. Similar to LNT listings, the MCL formulas listed in the article have
been only slightly edited in order to ease their presentation.

`labels.rename` is a utility file used to work around a limitation of CADP
concerning the formatting of values of sets of naturals, and how they can be
referred to in MCL formulas. This is an implementation detail that can be
ignored.

On a machine with CADP installed, you can run the verification procedure with:

```sh
cd cadp/mutex-standalone-example/
svl
```

This generates the state space of the mutex example for all our progress models,
and check the presence of potential deadlocks. It should produce a log similar
to `expected_output.log`. We can see for instance that for this mutex litmus
test, CADP reports potential deadlock under both weak and strong fairness for
the HSA progress model, but no risk of deadlock under the OBE progress model:

```sh
property DeadlockFreeWeak (mutex_HSA)
 | There is no deadlock under weak fairness in mutex_HSA

FAIL

property DeadlockFreeStrong (mutex_HSA)
 | There is no deadlock under strong fairness in mutex_HSA

FAIL

[...]

property DeadlockFreeWeak (mutex_OBE)
 | There is no deadlock under weak fairness in mutex_OBE

PASS

property DeadlockFreeStrong (mutex_OBE)
 | There is no deadlock under strong fairness in mutex_OBE

PASS
```

We also include a series of PDFs that represent the LTSs obtained for various
progress models. On a machine with CADP installed, the commands to reproduce
such PDFs are:

```sh
# You can change OBE with any other progress model name
lnt.open -root MAIN_OBE mutex.lnt generator m_OBE.bcg
bcg_labels -rename -total labels.rename m_OBE.bcg mutex_OBE.bcg
bcg_min mutex_OBE.bcg
bcg_draw -ps mutex_OBE.bcg
ps2pdf mutex_OBE.ps
```

### Processing the tests generated by Alloy

We have scripts to automatically process the litmus tests obtained with Alloy.

These scripts start from files produced by Alloy as an input, generate LNT and
SVL files, call CADP tools on them, and process the results. The top-level
script is `cadp/scripts/process.sh`, it is meant to be invoked on a directory
containing litmus test files produced by Alloy.

Our litmus tests are divided into directories with respect to the number of
threads and instructions present in the tests
(e.g. `2_threads_2_instructions`). The files produced by Alloy are under
`alloy_output` subdirectories.

On a machine with CADP installed, we can reproduce our experiments with these
commands:

```sh
cd cadp/
./scripts/process.sh 2_threads_2_instructions/alloy_output
./scripts/process.sh 2_threads_3_instructions/alloy_output
./scripts/process.sh 2_threads_4_instructions/alloy_output
./scripts/process.sh 3_threads_3_instructions/alloy_output
./scripts/process.sh 3_threads_4_instructions/alloy_output
```

On a powerful desktop machine (`Intel(R) Xeon(R) Gold 6154 CPU @ 3.00GHz`), here
is the approximate time it takes to process these various groups of tests:

| Test group               | # tests | Process time (min) |
|--------------------------|---------|--------------------|
| 2_threads_2_instructions | 8       | 14                 |
| 2_threads_3_instructions | 176     | 320                |
| 2_threads_4_instructions | 173     | 314                |
| 3_threads_3_instructions | 21      | 38                 |
| 3_threads_4_instructions | 105     | 194                |

Inside each test group directory, our scripts generate and populate the
`alloy_output_processed` and `checker_files` directories.

If you cannot easily install CADP, our artifact provides all expected output
files for the `2_threads_2_instructions` group. In order to keep the artifact
size under control, it includes only the `alloy_output_processed` part of the
expected results for other test groups.

In each test group, you can use a web browser to locally open the
`<test-group>/alloy_output_processed/testExplorer.html` and explore the results.

## Analysis of Synthesized Tests

### Qualitative Analysis of Synthesized Tests

Section 5.4 describes a Qualitative analysis of the tests. Most of this section requires manual inspection of all the tests. To ease this, we have created a _Test Explorer_ web interface to easier explore the tests. We have hosted a copy of this page [here](https://www.cs.princeton.edu/~ls24/testExplorer.html). To use this page, click on one of the tests on the right-hand-side. Note that the tests are organized by their conformance configuration (as described in Section 5). 

You should be able to match the configuration and ID given in table 3, with the corresponding test in the Test Explorer.

The test explorer is included in this repo in the `web_test_explorer` directory. This web app allows one to visualize for each test: (1) the instructions for each thread, (2) the resulting LTS, (3) the forward progress results for each scheduler, and (4) the Amber test generated for it (with no saturation techniques). To run it just open the HTML file in the directory with your browser of choice.

### Running Tests on Formal Models

Section 5.5 describes "Running Tests on Formal Models"

The code to do this is largely contained to python scripts to parse and analyze the synthesized Alloy tests and the results from running them on the CADP formal progress models. This code is contained in the `/data/synthesis_analysis` in the docker image.

Inside this directory, there is the results of running the Alloy tests through the formal models in the `formal_results` directory. Inside this, there is a directory for each of the 5 configurations from the test synthesis runs (e.g. `2_thread_2_instruction`). Inside each of these configuration directories is a directory called `schedulers` and then `.csv` files detailing each test ID and whether it passes or fails (i.e. potentially terminates) under each scheduler. We include this data whether or not you have run the full Alloy test synthesis run (not recommended) or the CADP tool.

We have provided scripts to parse and analyze these results in `/data/synthesis_analysis/result_analysis`. The first results to output are the results of Figure 8. To do this, first run the script to see the different percentages of strong and weak tests. This can be done by running:

`python3 strong_vs_weak.py`

The output of this shows the strong/weak percentages broken down per testing configuration. The left most bar of figure 8 is the total percentages shown at the end of the output.

Next, we want to get the data of Table 4. To do this, run:

`python3 mk_table_4.py`

This will display a nicely formatted visual table with the information of table 4 of the paper. The percentages shown in the table correspond to the right bars of figure 8.

The data file for figure out is in `data.dat`, and the gnuplot script to generate the graph is in `plot.gnu`. You can generate the graph by executing:

`gnuplot plot.gnu`

This will create `output.pdf` with the visual of figure 8.

## Emprical Testing

The empirical testing code is all found in the `/data/empirical_testing` directory on the docker image.

### C++ Code

The simplest empirical testing to do is to test multi-threaded C++ code as described in the beginning of Section 6.3. There should be no instances of non-termination, and thus these tests should run fairly quickly. 

We first generate the C++ code from our synthesized tests (found in `/data/empirical_testing/ALL_tests_flat`, which simply contains all of our synthesized tests in a flattened directory structure). To generate the the C++ code, go to the directory `test_cpp/code_gen`. There are two files to generate: the initialization, and the kernel. Both python scripts are called from the `to_run.sh` script. Please run this script. There will now be a `kernel_init.h`  file(containing kernel names and function headers)  and a `kernels.cpp`file (containing the kernel implementations). 

To run the C++ code, go to the `cpp_app` directory. Run `make` to build the application. You will then run both an under, and over, subscribed variant of the code (as described in Section 6.3). The commands to run this code are located in `to_run.sh`. These applications should take approximately 1 hour to run. You should see at the bottom of each output (see `to_run.sh` for the output files) the line `total tests killed: 0`, meaning that no tests timed out on C++. 

### Vulkan Code

While we understand that it may be infeasible for the reviewers to have access to the GPUs that we tested, we have installed a software GPU emulator software in the docker, called [Swift Shader](https://github.com/google/swiftshader). We test Vulkan through the [Amber](https://github.com/google/amber) testing framework. 

To do this, we synthesize Amber tests and run them from the same script. It first requires prepping some testing and result directories, and then running the tests. these steps are outlined in `to_run.sh`. 

We have set up a configuration to run each test for 1 iteration on Swift Shader through Amber. If you run the `to_run.sh` it should take around 30 minutes to finish running.

TODO Tyler: describe how to view the results

### CUDA

We have not tested running CUDA code through docker and thus we make no claims about its support. However, we have included the CUDA code gen (similar to the C++ code gen) and driver code. If access to a CUDA enabled device is available, the code from `empirical_testing/test_cuda` can be compiled in run.

There are three directories in `test_cuda`, one for each of our CUDA experiments. `test_plain` produces the tests used in Section 6.3. `test_coop` will generate code to test the CUDA cooperative groups (described in Section 6.4). `test_warp` will generate the code to test the warp scheduler also described in Section 6.4. 

Although the reviewers may not be able to run the code, in each directory, there is a `code_gen` directory that generates the CUDA code from our synthesized tests. For `test_plain` and `test_coop`, this includes tests with the _chunked_ and _round robin_ heuristics. We encourage the reviewers to run the `code_gen` for each (following the `to_run.sh` scripts). and examining the output of each script.

### Metal

Similar to CUDA, we do not believe building and deploying IOS applications is possible through this docker container. Nonetheless, we include a `code_gen` to generate metal kernels and swift initialization. We encourage reviewers to run the code in `code_gen` following the `run_me.sh` script. We have included xcode project files that can be copied to an OSX system to build and deploy an OSX testing harness, or an IOS application that can run on an Iphone or Ipad. 

We warn the reviewers that running the IOS application can cause alarming visual artifacts to appear on the device. Hopefully it goes without saying that we do not assume liability for any damage done to your devices when running our test harness (although we have run it many times over without permanant issue on an Iphone 11 and Ipad Air 3). That said, it is interesting and fun to run these tests on IOS devices and hope that some reviewer will be adventurous enough to try it! 

The results of our empirical runs are stored in `/data/empirical_analysis/empirical_results`. That directory contains a subfolder for each of the synthesis configurations (i.e. the number of threads and instructions). Each of these directories contains a sub directory for the three frameworks we tested: CUDA, Vulkan and Metal. Each of those directores contains a CSV describing the device we tested and the results of running each of the test. 

### Analyzing the Results

All the scripts discussed here are in the `analysis_scripts` directory.

The first analysis we perform is for Figure 9. To do this, go into the `figure_9` directory. First, we must generate the csv for figure 9. This is done by running:

`python3 mk_fig_9.py`

This creates `output.csv`. The pdf of figure 9 can then be made by running:

`gnuplot plot.gnu`

Next, we discuss how to check for LOBE conformance, as discussed in Section 6.3.2. This is done in the `check_lobe_conformance` directory. The empirical results (per device) can be checked against the formal LOBE results by running:

`python3 check.py`

You will see displayed on the output the per-device results. You should see that all devices, except the Mali and A12 pass. The two chips that fail have 11 failed tests. If you run the above command with a `-v` option, you will see the test configuration and id that failed (which you could then examine in the test explorer). 

Next, we will explore the uniform behaviors under the chunked hueristic (Section 6.3.3). This is given in the `check_lobe_tightness` directory. You run this check the same way that lobe conformance was checked. As described in the paper, you should observe that each device deterministically passes 5 of the distinguishing tests for the fully fair schedulers under the chunked hueristic. If you run with `-v` you can see more information about the 5 tests that pass.

### Additional results

Finally, we will check the two additional results discussed in Section 6.4. First we will check Nvidia cooperative groups. To do this, go into the `check_nvidia_cooperative_groups` directory. This directory has a similar `check.py` script to run. You should observe that all weak fairness tests pass, however several strong fairness tests fail. You can run with `-v` to observe more details about the failing tests. 

To check the Nvidia independent warp scheduler (IWS), go into `check_IWS_scheduler`. This directory also has a `check.py` script to run. You should see output indicating that the IWS setting passes all weak fairness tests, but the non-IWS setting fails many of them. Convsersly, the strong fairness tests should pass under the non-IWS setting, and have a relatively small number of failures with the IWS setting.

## Thanks!

Thanks for all your work! We're happy for any feedback and we hope you enjoyed reading our paper and running our code!
