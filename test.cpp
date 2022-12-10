#include <unordered_map>
#include <map>
#include <vector>
#include <string>


using namespace std;
struct Security
{
    string m_identifier;
    map<string, double> m_data;
};

Security makeSecurity()
{
    Security rv;
    for (auto ii = 0; ii < 10; ii++)
    {
        rv.m_data.insert(make_pair("field"+to_string(ii), double()));
    }
    static int uuid = 0;
    rv.m_identifier= to_string(++uuid);
    return rv;
};

struct StructPod
{
    double f0;
    double f1;
    double f2;
    double f3;
    double f4;
    double f5;
    double f6;
    double f7;
    double f8;
    double f9;

    StructPod(Security security)
    {
        f0 = security.m_data["field0"];
        f1 = security.m_data["field1"];
        f2 = security.m_data["field2"];
        f3 = security.m_data["field3"];
        f4 = security.m_data["field4"];
        f5 = security.m_data["field5"];
        f6 = security.m_data["field6"];
        f7 = security.m_data["field7"];
        f8 = security.m_data["field8"];
        f9 = security.m_data["field9"];
    }
};

struct MapLike
{
    map<string, double> m_internals;
    MapLike(const Security & security)
    {
        for (const auto & kv : security.m_data) 
        {
            m_internals[kv.first] = kv.second;
        }
    }
};

template<typename T>
void handle(const vector<Security> & allSecurities)
{
    unordered_map<string, T> container;
    for (const auto & security : allSecurities)
    {
        T element(security);
        container.insert(make_pair(security.m_identifier, element));
    }
}

//#define TEST
#if defined(TEST)
namespace benchmark
{
    using State = vector<int>;
    template <typename T>
        void DoNotOptimize(const T &);
}

#define BENCHMARK(ignored)
#endif // TEST

static void ParseToPod(benchmark::State& state) {
    // Code inside this loop is measured repeatedly
    vector<Security> securities(1000);
    handle<StructPod>(securities);
}
// Register the function as a benchmark
BENCHMARK(ParseToPod);

static void ParseToMapLike(benchmark::State& state) {
    // Code before the loop is not measured
    vector<Security> securities(1000);
    handle<MapLike>(securities);
}
BENCHMARK(ParseToMapLike);

int main(int argc, const char * argv[])
{ return 0; }
