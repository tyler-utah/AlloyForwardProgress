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
