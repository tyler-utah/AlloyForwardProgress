FROM ubuntu:18.04

ENV \
  LC_ALL=C.UTF-8 LANG=C.UTF-8

# Install useful packages
RUN \
  apt-get -qq update && \
  apt-get -y -qq install openjdk-8-jdk curl && \
  update-java-alternatives --set java-1.8.0-openjdk-amd64 && \
  apt-get -y install git && \
  apt-get -y install python3 && \
  apt-get -y install cmake && \
  apt-get install ninja-build && \
  apt-get -y install build-essential && \
  apt-get -y install software-properties-common && \
  apt-get -y install wget && \
  apt-get -y install libssl-dev && \
  apt-get -y install locate && \
  apt-get -y install libxext-dev && \
  apt-get -y install zlib1g-dev && \
  apt-get -y install emacs && \
  apt-get -y install python3-pip && \
  apt-get -y install vulkan-utils && \
  apt-get -y install unzip && \
  pip3 install tabulate

# Install Alloy
#RUN \
#  mkdir -p /data/alloy && \
#  cd /data/alloy && \
#  curl -fksLS --http1.1 --retry 3 -O https://github.com/AlloyTools/org.alloytools.alloy/releases/download/v5.1.0/org.alloytools.alloy.dist.jar

# Install recent version of cmake (required by swiftshader)
RUN \
   mkdir -p /data/cmake && \
   cd /data/cmake && \
   wget https://github.com/Kitware/CMake/releases/download/v3.21.0-rc2/cmake-3.21.0-rc2.tar.gz && \
   tar -xzf cmake-3.21.0-rc2.tar.gz && \
   cd cmake-3.21.0-rc2 && \
   ./bootstrap && \
   make -j8 && \
   make install

# Install Amber
RUN \
    mkdir -p /data/amber && \
    cd /data/amber && \
    git clone https://github.com/google/amber.git && \
    cd amber && \
    ./tools/git-sync-deps --with-swiftshader && \
    mkdir -p out/Debug && \
    cd out/Debug && \
    cmake -GNinja -DAMBER_ENABLE_SWIFTSHADER=True ../.. && \
    ninja -j8

ENV VK_ICD_FILENAMES=/data/amber/amber/out/Debug/Linux/vk_swiftshader_icd.json

# Get C++ tester code copied over
RUN \
   mkdir -p /data/paper_experiments && \
   mkdir -p /data/test_synthesis

COPY ./to_copy/empirical_testing /data/paper_experiments/

COPY ./to_copy/test_synthesis /data/test_synthesis

# Getting and building Alloy
RUN \
   cd /data/test_synthesis && \
   cd alloy5 && \
   ./gradlew && \
   ./gradlew build  

# Login shell
CMD ["/bin/bash", "--login"]
