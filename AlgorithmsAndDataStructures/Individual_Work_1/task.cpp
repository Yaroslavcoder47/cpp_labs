#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;


int findSubsequence(std::vector<int>& arr) {
    vector<int> list;
    for (int x : arr) {
        auto it = lower_bound(list.begin(), list.end(), x);
        if (it == list.end()) {
            list.push_back(x);
        } else {
            *it = x;
        }
    }
    
    return list.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    
    int r = findSubsequence(arr);

    for(int i = 0; i < n - 1; ++i){
        if(arr[i] >= arr[i + 1]){
            vector<int> mod_arr(arr);
            mod_arr.erase(mod_arr.begin() + i);
            int res = findSubsequence(mod_arr) + 1;
            
            r = max(r, res);
               
        }
    }
    cout << r;
    return 0;
}