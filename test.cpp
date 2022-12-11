#include "benchmark/benchmark.h"
#include <map>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

using namespace std;

constexpr string_view field0 = "field0";
constexpr string_view field1 = "field1";
constexpr string_view field2 = "field2";
constexpr string_view field3 = "field3";
constexpr string_view field4 = "field4";
constexpr string_view field5 = "field5";
constexpr string_view field6 = "field6";

struct Security {
  string m_identifier;
  map<string, double> m_data;
};

Security makeSecurity() {
  Security rv;
  for (auto ii = 0; ii < 7; ii++) {
    rv.m_data.insert(make_pair("field" + to_string(ii), double()));
  }
  static int uuid = 0;
  rv.m_identifier = to_string(++uuid);
  return rv;
};

struct StructPod {
  double f0;
  double f1;
  double f2;
  double f3;
  double f4;
  bool f5;
  bool f6;

  StructPod(Security security) {
    for (const auto &kv : security.m_data) {
      if (kv.first == field0)
        f0 = kv.second;
      else if (kv.first == field1)
        f1 = kv.second;
      else if (kv.first == field2)
        f2 = kv.second;
      else if (kv.first == field3)
        f3 = kv.second;
      else if (kv.first == field4)
        f4 = kv.second;
      else if (kv.first == field5)
        f5 = kv.second;
      else if (kv.first == field6)
        f6 = kv.second;
    }
  }
};

struct MapLike {
  map<string, variant<double, bool, string>> m_internals;
  MapLike(const Security &security) {
    for (const auto &kv : security.m_data) {
      m_internals[kv.first] = kv.second;
    }
  }
};

template <typename T> void handle(const vector<Security> &allSecurities) {
  unordered_map<string, T> container;
  for (const auto &security : allSecurities) {
    T element(security);
    container.insert(make_pair(security.m_identifier, element));
  }
}

const int nSecurities = 100;
vector<Security> securities(nSecurities);

static void ParseToPod(benchmark::State &state) {
  for (auto _ : state) {
    handle<StructPod>(securities);
  }
}
// Register the function as a benchmark
BENCHMARK(ParseToPod);

static void ParseToMapLike(benchmark::State &state) {
  // Code before the loop is not measured
  for (auto _ : state) {
    handle<MapLike>(securities);
  }
}
BENCHMARK(ParseToMapLike);

BENCHMARK_MAIN();
