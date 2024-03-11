#include <iostream>
#include <vector>
#include <map>
#include "task1.h"
#include <spdlog/spdlog.h>

using std::cin;
using std::cout;

int main()
{
    int size;
    cout << "Enter size array: ";
    cin >> size;
    cout << "Enter array:\n";
    std::vector<int> data;
    data = inputList(std::cin, size);
    deleteSameElements(data);
    for (const auto& tmp : data) {
        cout << tmp << ' ';
    }

    return 0;
}