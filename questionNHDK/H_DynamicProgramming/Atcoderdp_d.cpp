#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 1e5+5;


int dp[MAXN];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,W;
    cin >> n >> W;
    int w,v;
    for(int i = 1; i <= n; i++){
        cin >> w >> v;
        for(int j = W; j >= w; j--){
            if(j - w >= 0)dp[j] = max(dp[j],dp[j-w]+v);
        }
    }
    cout << dp[W];
}


/*
int dp[105][MAXN];
int w[105],v[105];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,W;
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int k = W; k >= 0; k--){
            if(k-w[i] >= 0)dp[i][k] = max(dp[i-1][k],dp[i-1][k-w[i]]+v[i]);
            else dp[i][k] = dp[i-1][k];
        }
    }
    cout << dp[n][W];
}

*/