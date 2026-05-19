#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;
using namespace chrono;

int countPairs1(int *arr, int len, int value);
int countPairs2(int *arr, int len, int value);
int countPairs3(int *arr, int len, int value);

int main()
{
    ofstream file("results.csv");

    file << "len,t1,t2,t3\n";

    random_device rd;
    mt19937 gen(rd());

    for (int len = 1000; len <= 20000; len += 1000)
    {
        vector<int> arr(len);

        uniform_int_distribution<> dis(0, 100000);

        for (int i = 0; i < len; i++)
        {
            arr[i] = dis(gen);
        }

        sort(arr.begin(), arr.end());

        int value = 50000;

        auto start1 = high_resolution_clock::now();
        countPairs1(arr.data(), len, value);
        auto end1 = high_resolution_clock::now();

        auto start2 = high_resolution_clock::now();
        countPairs2(arr.data(), len, value);
        auto end2 = high_resolution_clock::now();

        auto start3 = high_resolution_clock::now();
        countPairs3(arr.data(), len, value);
        auto end3 = high_resolution_clock::now();

        auto t1 = duration_cast<microseconds>(end1 - start1).count();
        auto t2 = duration_cast<microseconds>(end2 - start2).count();
        auto t3 = duration_cast<microseconds>(end3 - start3).count();

        file << len << ","
             << t1 << ","
             << t2 << ","
             << t3 << "\n";

        cout << "len = " << len << endl;
    }

    file.close();

    return 0;
}
