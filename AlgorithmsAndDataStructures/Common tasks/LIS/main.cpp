#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
 
    int a[70000];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }


    int dp[70000];
    for(int i = 0; i < n; ++i)
    {
        dp[i] = 1;
    }

    for(int i = 1; i < n; ++i){
        int max_el = dp[0];
        for(int j = 0;  j < i; ++j){
            if(a[j] < a[i] && dp[j] >= max_el){
                max_el = dp[j];
            }
        }
        dp[i] = max_el + 1;
    }

    cout << dp[n-1];
    return 0;
}