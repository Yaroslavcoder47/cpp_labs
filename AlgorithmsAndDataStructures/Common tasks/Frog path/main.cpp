#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int a[100000], n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[0] << '\n' << 1;
    }
    else if(n == 2){
        cout << -1;
    }
    else{
        int mosq[100000];
        for(int i = 0; i < n; ++i){
            mosq[i] = -1;
        }
        mosq[0] = a[0];
        mosq[2] = a[2] + a[0];
        mosq[3] = a[3] + a[0];

        int prev[100000];
        for(int i = 0; i < n; ++i){
            prev[i] = -1;
        }
        prev[1] = 0;
        prev[2] = 0;
        prev[3] = 0;
        
        for(int i = 4; i < n; ++i){
            if(mosq[i-2] > mosq[i-3]){
                mosq[i] = a[i] + mosq[i-2];
                prev[i] = i-2;
            }
            else{
                mosq[i] = a[i] + mosq[i-3];
                prev[i] = i-3;
            }
        }
        cout << mosq[n-1] << '\n';
        if(mosq[n-1] != -1){
            vector<int> path;
            for(int i = n-1, j = 0; i != -1; i=prev[i], j++){       
                path.push_back(i + 1);
            }
            for(int j = path.size()-1; j >= 0; --j){
                cout << path[j] << ' ';
            }
        }
    }

    return 0;
}