#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[1000];
    int b[1000];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i = 1; i < n+1; ++i){
        for(int j = 1; j < n+1; ++j){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int k = dp[n][n];
    vector<int> a_ind;
    vector<int> b_ind;
    int i = n, j = n;

    while(i > 0 && j > 0){
            if(a[i-1] == b[j-1]){
                a_ind.push_back(i-1);
                b_ind.push_back(j-1);
                i -= 1;
                j -= 1;
            }
            else if(dp[i][j-1] >= dp[i-1][j]){
                j -= 1;
            }
            else{
                i -= 1;
            }
    }

    reverse(a_ind.begin(), a_ind.end());
    reverse(b_ind.begin(), b_ind.end());

    cout << k << '\n';
    for(int i : a_ind){
        cout << i << ' ';
    }
    cout << '\n';
    for(int i : b_ind){
        cout << i << ' ';
    }
    
}