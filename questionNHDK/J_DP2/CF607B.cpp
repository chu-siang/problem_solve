#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[505][505];
signed main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    for(int i = 1; i <= n; ++i)cin >> v[i];
    memset(dp,1,sizeof(dp));
    for(int i = 1; i <= n; ++i)dp[i][i] = dp[i][i-1] = 1;
    for(int l = 2; l <= n; ++l){
        for(int st = 1; st <= n -l + 1; ++st){
            int en = st + l -1;
            if(v[st] == v[en])dp[st][en] = dp[st+1][en-1];
            for(int j = st; j < en; ++j){
                dp[st][en] = min(dp[st][en],dp[st][j]+dp[j+1][en]);
            }
        }
    }
    cout << dp[1][n] << '\n';
}