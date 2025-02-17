#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    fin >> s;

    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = 0; i < n; ++i){
        dp[i][i] = 1;
    }

    for(int l = 2; l <= n; ++l){
        for(int i = 0; i <= n - l; ++i){
            int j = i + l - 1;
            
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }

    string palindrome(dp[0][n-1], ' ');
    int i = 0, j = n - 1, left = 0, right = dp[0][n-1] - 1;
    while(i <= j)
    {
        if(s[i] == s[j]){
            palindrome[left] = s[i];
            ++left;
            palindrome[right] = s[i];
            --right;
            ++i;
            --j;
        }
        else if(dp[i+1][j] > dp[i][j-1]){
            ++i;
        }
        else{
            --j;
        }
    }

    fout << dp[0][n-1] << '\n' << palindrome;
    return 0;
}