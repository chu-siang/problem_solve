//有限背包 問題
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int v[MAXN],w[MAXN],h[105],s[105],k[105],dp[MAXN];
signed main(){
    int n,x;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        int m = k[i];
        for(int j = 1; m >= j; j+=j){
            w[++num] = h[i]*j,v[num]=s[i]*j;
            m-=j;
        }
        if(m > 0)w[++num] = h[i]*m,v[num]=s[i]*m;
    }
    for(int i = 1; i <= num; i++){
        for(int j = x; j >= w[i]; j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= x; i++)ans = max(ans,dp[i]);
    cout << ans << '\n';
}