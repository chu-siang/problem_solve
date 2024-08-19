//無限背包
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;
const int MOD  = 1e9+7;
int dp[MAXN];
signed main(){
    int n,x;
    cin >> n >> x;
    int c;
    fill(dp,dp+MAXN,0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> c;
        for(int j = c; j <= x; j++){
            dp[j] += (dp[j-c])%MOD;
            dp[j]%=MOD;
        }
    }
    cout << dp[x];
}