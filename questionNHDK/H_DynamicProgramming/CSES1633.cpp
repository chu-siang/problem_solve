#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;
int dp[MAXN];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(i,6LL); j++){
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n];
}
