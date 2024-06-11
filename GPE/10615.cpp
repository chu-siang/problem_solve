#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
bool dp[2][MAXN];

signed main(){
    short n,k;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        short a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] %= k;
        }
        if(a[0] < 0)a[0]+=k;
        memset(dp,0,sizeof(dp));
        bool f = 0;
        dp[0][a[0]] = 1;
        for(int i = 1; i < n; i++){
            f^=1;
            memset(dp[f],0,sizeof(dp[f]));
            for(int j = 0; j < k; j++){
                if(dp[f^1][j]) dp[f][(j+k+a[i])%k] = dp[f][(j+k-a[i])%k] = 1; 
            }
        }
        if(dp[f][0])cout <<"Divisible\n";
        else cout << "Not divisible\n"; 
    }
    
}