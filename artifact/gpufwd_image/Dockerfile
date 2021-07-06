FROM ubuntu:18.04

ENV \
  LC_ALL=C.UTF-8 LANG=C.UTF-8

# Install useful packages
RUN \
  apt-get -qq update && \
  apt-get -y -qq install openjdk-8-jdk curl && \
  update-java-alternatives --set java-1.8.0-openjdk-amd64

# Install Alloy
RUN \
  mkdir -p /data/alloy && \
  cd /data/alloy && \
  curl -fksLS --http1.1 --retry 3 -O https://github.com/AlloyTools/org.alloytools.alloy/releases/download/v5.1.0/org.alloytools.alloy.dist.jar

# Login shell
CMD ["/bin/bash", "--login"]
