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
    fill(dp,dp+100001,(int)1e18);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> w >> v;
        for(int j = 100000; j >= v; j--){
            dp[j] = min(dp[j],dp[j-v]+w);
        }
    }
    int ans = 0;
    for(int i = 0; i <= 100000; i++)if(W >= dp[i])ans = max(ans,i);
    cout << ans << '\n';
}

