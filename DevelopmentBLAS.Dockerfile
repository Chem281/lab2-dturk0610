# TODO
FROM cppdev/latest as build

RUN apt-get clean && \
    apt-get update --fix-missing && \
    apt-get install -y \
    libblas-dev