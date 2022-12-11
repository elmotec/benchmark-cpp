# syntax=docker/dockerfile:1.4
FROM debian:bookworm as builder

RUN apt-get -qq -y update \
&& apt-get install --no-install-recommends -y \
apt-utils \
binutils \
clangd \
clangd-14 \
cmake \
g++ \
gdb \
git \
make \
neovim \
nodejs \
&& rm -rf /var/lib/apt/lists/*

