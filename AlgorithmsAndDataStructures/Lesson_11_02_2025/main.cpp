#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    vector<long> arr;
    long num;
    while (fin>>num) {
        arr.push_back(num);
    }
    set<long> arr_without_duplicates(arr.begin(), arr.end());
    long long sum = 0;
    for (long i : arr_without_duplicates) {
        sum += i;
    }
    fout << sum;
    fin.close();
    return 0;
}