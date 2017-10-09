#include <iostream>
#include <chrono>
#include "xrange.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::microseconds;

template<typename Type> void test()
{
    high_resolution_clock::time_point t0 = high_resolution_clock::now();

    for (auto i : xrange<Type>(0, 1000000)) {
        continue;
    }

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    long long time_elapsed = duration_cast<microseconds>(t1 - t0).count();

    std::cout << "Time: " << time_elapsed << " us" << std::endl;
}

int main()
{
    test<int>();
    test<long long>();
    test<float>();
    test<double>();
    test<long double>();

    return 0;
}