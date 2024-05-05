#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

int dp[MAXN];
int c[105];


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> c[i];
    fill(dp,dp+MAXN,(int)1e18);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = c[i]; j <= 1e6; j++){
            dp[j] = min(dp[j],dp[j-c[i]]+1);
        }
    }
    if(dp[x] != 1e18)cout << dp[x] << '\n';
    else cout << "-1" << '\n';
}

