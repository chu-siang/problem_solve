#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;
int dp[MAXN];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,x;
    cin >> n >> x;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        for(int j = coin; j <= x; j++){
            dp[j] += (dp[j-coin])%MOD;
            dp[j]%=MOD;
        }
    }
    cout << dp[x];
}


/*
const int MOD = 1e9+7;
const int MAXN = 1e6+5;
int dp[2][MAXN];
int c[105];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++)cin >> c[i];
    c[0] = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            if(j - c[i] >= 0){
                dp[(i%2)][j] = dp[(i+1)%2][j]+dp[(i%2)][j - c[i]];
                dp[(i%2)][j] %= MOD;
            }else dp[i%2][j] = dp[(i+1)%2][j];
        }
    }
    cout << (dp[n%2][x]%MOD+MOD)%MOD;
}
*/