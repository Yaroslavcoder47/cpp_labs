#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    int mod = 1000000007;
    cin >> n >> k;
    if(n == 0 && k == 0){
        cout << 0;
        return 0;
    }
    long long numerator = 1;
    for(int i = n - k + 1; i <=n; ++i){
        numerator = (numerator * i) % mod;
    }
    long long denominator = 1;
    for(int i = 2; i <=k; ++i){
        denominator = (denominator * i) % mod;
    }
    long long denominator_new = 1;
    long long a = mod - 2;
    while(a > 0){
        if(a % 2){
            denominator_new = (denominator_new * denominator) % mod;
        }
        denominator = (denominator * denominator) % mod;
        a /= 2;
    }

    cout << (numerator * denominator_new) % mod;
    return 0;
}
