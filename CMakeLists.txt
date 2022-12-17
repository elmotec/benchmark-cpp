project(benchmark-cpp CXX)
cmake_minimum_required(VERSION 3.22)

include(FetchContent)

set(CMAKE_BUILD_TYPE RelWithDebugInfo)
set(CMAKE_COMPILER_ID GNU)
#set(CMAKE_CXX_COMPILER /usr/bin/gcc)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED On)

FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        v1.7.1
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE INTERNAL "Google benchmark tests off")
FetchContent_MakeAvailable(benchmark)

add_executable(bmk bmk.cpp)
target_compile_options(bmk PUBLIC -pg)
target_link_options(bmk PUBLIC -pg)
target_link_libraries(bmk benchmark::benchmark)

