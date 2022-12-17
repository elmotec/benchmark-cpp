# Benchmark-cpp

This repository makes it easy to quickly whip out a C++ benchmark using the awesome [Google Benchmark](https://github.com/google/benchmark). In one command `make`, it downloads the Google library, builds with [CMake](https://cmake.org/documentation/) and generates a _bmk_ binary from the `bmk.cpp` in the root folder.

To communicate your findings, copy and paste the content of `bmk.cpp` into the wonderful [quick bench](https://quick-bench.com/).

## Usage

1. Clone this repository.
2. Edit `bmk.cpp` to implement and debug your tests (a profile.out is generated to make sure everything is hit), see [Google Benchmark documentation](https://github.com/google/benchmark/blob/main/docs/user_guide.md) for details.
3. `make` and back to 2 if you need to debug.
5. (optional) copy and paste bmk.cpp into [quick bench](https://quick-bench.com/).


