#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int bin_search_left(int left, int right, vector<int>& arr, int x){
    if(left >= right){
        if(arr[left] == x){
            return left;
        }
        return -1;
    }

    int mid = left + (right - left) / 2;

    if(arr[mid] >= x){
        return bin_search_left(left, mid - 1, arr, x);
    }
    else{
        return bin_search_left(mid + 1, right, arr, x);
    }
}

int bin_search_right(int left, int right, vector<int>& arr, int x){
    if(left > right){
        return -1;
    }

    int mid = left + (right - left) / 2;
   
    if(arr[mid] > x){
        return bin_search_right(left, mid - 1, arr, x);
    }
    else{
        int val = bin_search_right(mid + 1, right, arr, x);
        if(val == -1 && arr[mid] == x){
            return mid;
        }
        return val;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int b, l, r;
    int x;
    
    for(int i = 0; i < k; ++i){
  
        cin >> x;
        if(x == 0){
            
        }
        b = 1;
        l = bin_search_left(0, arr.size(), arr, x);
        r = bin_search_right(0, arr.size(), arr, x) + 1;

        if(l == -1){
            b = 0;
            l = n;
            r = n;
        }
        
        cout << b << ' ' << l << ' ' << r  << '\n';

    }
    // int x;
    // cin >> x;
    // cout << bin_search_right(0, arr.size(), arr, x);
    
    return 0;
}