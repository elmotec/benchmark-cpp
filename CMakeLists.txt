cmake_policy(SET CMP0048 NEW)
project(benchmark-cpp
    VERSION 1.0.0
    DESCRIPTION "Google Benchmark wrapper for C++"
    HOMEPAGE_URL "https://github.com/elmotec/benchmark-cpp"
    LANGUAGES CXX
    )
cmake_minimum_required(VERSION 3.22.1)

include(FetchContent)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED On)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_COMPILER_ID "GNU")

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
target_link_libraries(bmk benchmark::benchmark_main)

