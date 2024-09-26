# TODO
FROM ubuntu:22.04 as build

RUN apt-get clean && \
    apt-get update --fix-missing && \
    apt-get install -y \
    gcc \
    make \
    cmake \
    git \
    lcov \
    nano \
    build-essential
