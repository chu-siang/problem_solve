#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 105;
int arr[MAXN][MAXN];

signed main(){
    int t;
    cin >> t;
    int C = 1;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        bool flag = true;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(i == j)continue;
                if(arr[i][j] != arr[j][i]){
                    flag = false;
                    break;
                }
            }
        }
        cout << "Test #"<< C++ << ":";
        if(flag)cout << " Symmetric.\n";
        else cout << " Non-symmetric.\n";
    }
}