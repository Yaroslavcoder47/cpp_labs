#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int bin_upper(int left, int right, vector<int>& arr, int x){
    while(left < right){
        int mid = (right + left) / 2;
        if(x <= arr[mid]){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
 
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        fin >> a[i];
    }

    vector<int> dp;
    
    for(int i = 0; i < n; ++i){
        int index = bin_upper(0, dp.size(), dp, a[i]);
        if(index == dp.size()){
            dp.push_back(a[i]);
        }
        else{
            dp[index] = a[i];
        }
    }

    fout << dp.size();
    return 0;
}