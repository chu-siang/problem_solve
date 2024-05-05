#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;
int dp[MAXN],c[105];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> c[i];
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= n; j++){
            if(i - c[j] >= 0){
                dp[i] += dp[i-c[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x];

}