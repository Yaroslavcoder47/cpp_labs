#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

#define INF 2147483647

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int s;
    fin >> s;
    
    vector<pair<int, int>> matr(s, pair<int, int>(s, 2));
    for(int i = 0; i < s; ++i){
        fin >> matr[i].first >> matr[i].second;
    }

    vector<vector<int>> m(s, vector<int>(s, 0));
    
    for(int l = 1; l < s; ++l){
        for(int i = 0; i < s - l; ++i){
            int j = i + l;
            m[i][j] = INF;
            for(int k = i; k < j; ++k){
                int res = m[i][k] + m[k+1][j] + matr[i].first * matr[k].second * matr[j].second;
                if(res < m[i][j]){
                    m[i][j] = res;
                }
            }

        }
    }
    
    fout << m[0][s-1];

    return 0;
}