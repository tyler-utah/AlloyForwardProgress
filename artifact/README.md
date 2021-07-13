# Artifact for "Specifying and Testing GPU Workgroup Progress Models"

## Abstract

This is the OOPSLA '21 artifact for the paper "Specifying and Testing GPU Workgroup Progress Models". We assume that the user has read the paper, and this documentation will refer to the paper (and use notation from the paper) throughout. 

We admit that this artifact might be different than traditional artifacts submitted to OOPLSA. Our results are not reproducible on traditional linux servers. If you have read the paper, you will notice that we test a diversity of devices, from Iphones, to Ipads, to Android tablets. We have done a best-effort to show that our results are reproducible and have included all software to reproduce our results. 

of the formal tools we use, [CADP](https://en.wikipedia.org/wiki/Construction_and_Analysis_of_Distributed_Processes), requires a license to run. Academic licenses are free and easily acquired with a simple email form; however, we could not legally bundle the source (or an executable) of this tool. We hope the evaluators will follow our simple rules for obtaining the tool to run this section of experiments.

While we appreciate that the evaluators may not have access to the GPUs we used in our experiments, we have included the ability to run our experiments on a software-emulated GPU called [Swift Shader](https://github.com/google/swiftshader). We have included all data from running our experiments across a diversity of devices.

Our synthesis results require over 1 month of execution time on a big server. We have included scripts to run a subset of the synthesis runs. 

We hope the AE committee will consider the unique components of our work and appreciate the wide applicability of our experiments (even if they are not easily reproduced in a clean traditional academic environment).

## Getting started

These instructions have been tested on a 64-bit Linux machine running an OS
similar to Ubuntu 18.04 with Docker installed and with Bash as the shell. Most of our software is included in the docker image. All data and most software required for the artifact is also included in this repository in the `to_copy` directory.

## Accessing the docker image

This repo contains the necessary data and scripts to build a docker container; however, this can be a lengthy process. For convenience, we have provided a pre-built docker image at: TODO

To launch the docker image, please run: TODO

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

sudo docker stop gpufwd-container  # May fail.
sudo docker rm gpufwd-container    # May fail.
sudo docker create -it --name gpufwd-container gpufwd-image

sudo docker start -ia gpufwd-container
```

You should now have a Bash shell inside the container.

## Test Generation

We begin by discussing the test synthesis process described in Section 5 "Automatic Synthesis of Progress Litmus Tests". This component requires a slightly modified version of the [Alloy](https://alloytools.org/) relational model checker, which we have included in this repo, copied into the docker and built.



## CADP: model-checking test termination

In Section 4 "Executable Semantics of Progress Models", we describe how we use
the CADP verification toolbox to automatically check whether a given litmus test
is guaranteed to terminate under various progress models. Here we describe how
to install CADP, and how to run our scripts that use CADP to do the
verification.

To run these experiments, change into the `/data/test_synthesis/alloy5` directory. Recall from the paper, that there are 5 different test configurations, which vary the number of threads and instructions in the synthesis run. 

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

## Emprical Testing

### C++ Code

_TODO: Tyler: this should work_

### Vulkan Code

_TODO: Tyler: install amber and switftshader_

### CUDA and Metal Code

_TODO: Tyler: will not be able to execute, but we can provide the xcode projects_

## Data

_TODO: Tyler_
