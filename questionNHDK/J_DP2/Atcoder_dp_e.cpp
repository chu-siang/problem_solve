#include<bits/stdc++.h>
#define int long long
using namespace std;

int w[105],v[105];
int dp[100005];
signed main(){
    int n,x;
    cin >> n >> x;
    int sum = 0 ;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    fill(dp,dp+100005,1e12);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = sum; j >= v[i]; j--){
            dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= sum; ++i)if(dp[i] <= x)ans = max(ans,i);
    cout << ans << '\n';
}