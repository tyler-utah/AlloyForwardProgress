# Artifact for "Specifying and Testing GPU Workgroup Progress Models"

## Abstract

TODO

## Getting started

These instructions have been tested on a 64-bit Linux machine running an OS
similar to Ubuntu 18.04 with Docker installed and with Bash as the shell. Other
configurations are likely to work since we mostly use Docker.

## Build the docker image

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

_TODO: Tyler and Lucas figure out how to get test generation running_

_TODO: instructions for running 2 thread 2 instruction variants_

_TODO: State that running larger experiments require tons of time and tons of RAM_

_TODO: point to Lucas Test explorer, both the Princeton hosted page and the git repo, as well as generated raw tests
> Hugues: we can probably include the html pages directly in the artifact image, for local browsing?

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

If you cannot easily install CADP, our artifact provides the results for the
`2_threads_2_instructions` group. In particular, the
`2_threads_2_instructions/alloy_output_processed/testExplorer.html` file can be
open locally with a web browser to explore the test results.

## Emprical Testing

### C++ Code

_TODO: Tyler: this should work_

### Vulkan Code

_TODO: Tyler: install amber and switftshader_

### CUDA and Metal Code

_TODO: Tyler: will not be able to execute, but we can provide the xcode projects_

## Data

_TODO: Tyler_
