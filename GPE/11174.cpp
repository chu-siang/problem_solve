#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e4+5;
int dp[MAXN];
signed main(){
    int m,n,t;
    while(cin >> m >> n >> t){
        memset(dp,-2e5,sizeof(dp));
        dp[0] = 0;
        for(int i = m; i <= t; i++){
            if(dp[i-m]+1 > dp[i])dp[i] = dp[i-m]+1;
        }
        for(int i = n; i <= t; i++){
            if(dp[i-n]+1 > dp[i])dp[i] = dp[i-n]+1;
        }
        int e = t;
        while(dp[e]<0)e--;
        cout << dp[e];
        if(e==t)cout << '\n';
        else cout << ' ' << t-e << '\n'; 
    }
}