#include <iostream>
#include <chrono>
#include "xrange.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::cout;
using std::endl;


template<typename Type>
void test()
{
    high_resolution_clock::time_point before = high_resolution_clock::now();

    for (auto i : Xrange<Type>(0, 10000000, 1));

    high_resolution_clock::time_point after = high_resolution_clock::now();

    long long time_elapsed = duration_cast<microseconds>(after - before).count();

    cout << "Time: " << time_elapsed << " us" << endl;
}


int main()
{
	for (auto i : xrange(10))
		cout << i << " ";
    cout << endl;

    for (auto i : xrange(5))
    {
        test<int>();
        test<long long>();
        cout << endl;
    }
    //test<float>();
    //test<double>();
    //test<long double>();

    return 0;
}