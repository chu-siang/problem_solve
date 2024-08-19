#include<bits/stdc++.h>
#define int long long
using namespace std;

int w[105],v[105];
int dp[100005];
signed main(){
    int n,x;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n; i++){
        for(int j = x; j >= w[i] ; j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout << dp[x];
}