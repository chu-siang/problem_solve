//01背包
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+5;


int dp[MAXN];
int w[MAXN];
signed main(){
    int n,x;
    cin >> n >> x;
    int v;
    for(int i = 0; i < n; i++)cin >> w[i];
    for(int i = 0; i < n; i++){
        cin >> v;
        for(int j = x; j >= w[i]; j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v);
        }
    }
    cout << dp[x];
}
/*
int w[MAXN],v[MAXN];
int dp[MAXN][MAXN];
signed main(){
    int n,x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++)cin >> w[i];
    for(int i = 1; i <= n; i++)cin >> v[i];
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= 0; j--){
            if(j-w[i] >= 0)dp[i][j] = max (dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][x];
}*/