#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+5;
int dp[4][MAXN];
int a[MAXN],b[MAXN],c[MAXN];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int k;
    dp[1][1] = a[1],dp[2][1] = b[1],dp[3][1] = c[1];
    for(int i = 2; i <= n; i++){
        dp[1][i] = max(dp[2][i-1],dp[3][i-1])+a[i];
        dp[2][i] = max(dp[1][i-1],dp[3][i-1])+b[i];
        dp[3][i] = max(dp[1][i-1],dp[2][i-1])+c[i];
    }
    cout << max({dp[1][n],dp[2][n],dp[3][n]});
}