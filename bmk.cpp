#include "benchmark/benchmark.h"
#include <vector>
#include <optional>
#include <memory>

using namespace std;

template <typename T>
void handle() {
  vector<T> v(1000);
  benchmark::DoNotOptimize(v);
}

static void buildVectorOfUniquePtrs(benchmark::State &state) {
  // Code before the loop is not measured
  for (auto _ : state) {
    handle<unique_ptr<double>>();
  }
}
// Register the function as a benchmark
BENCHMARK(buildVectorOfUniquePtrs);

static void buildVectorOfOptionals(benchmark::State &state) {
  // Code before the loop is not measured
  for (auto _ : state) {
    handle<optional<double>>();
  }
}
// Register the function as a benchmark
BENCHMARK(buildVectorOfOptionals);

static void buildVectorOfPods(benchmark::State &state) {
  // Code before the loop is not measured
  for (auto _ : state) {
    handle<double>();
  }
}
// Register the function as a benchmark
BENCHMARK(buildVectorOfPods);
