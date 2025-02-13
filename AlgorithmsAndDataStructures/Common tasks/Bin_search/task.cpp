#include <iostream>

using namespace std;

int bin_search(int left, int right, int* arr, int x){
    while(left < right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == x){
            return 1;
        }
        else if(x < arr[mid]){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return 0;
}

int lower_bin_search(int left, int right, int* arr, int x){
    while(left < right){
        int mid = left + (right - left) / 2;
        if(x <= arr[mid]){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int upper_bin_search(int left, int right, int* arr, int x){
    while(left < right){
        int mid = left + (right - left) / 2;
        if(x < arr[mid]){
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
    int n;
    cin >> n;
    int a[300000];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int k;
    cin >> k;
    int x;
    for(int i = 0; i < k; ++i){
        cin >> x;
        cout << bin_search(0, n, a, x) << ' '<< lower_bin_search(0, n, a, x) << ' ' << upper_bin_search(0, n, a, x) << '\n';
    }
  
    return 0;
}