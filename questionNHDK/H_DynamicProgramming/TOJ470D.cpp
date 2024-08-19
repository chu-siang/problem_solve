#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6+5;
int dp[MAXN],a[MAXN];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    bool flag = false;
    while(cin >> n){
        if(flag)cout << '\n';
        flag = true;
        for(int i = 1; i <= n; i++)cin >> a[i];
        memset(dp,0,sizeof(dp));
        dp[0] = 0,dp[1] = max(0LL,a[1]);
        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1],dp[i-2]+a[i]);
        }
        cout << dp[n];
    }
}