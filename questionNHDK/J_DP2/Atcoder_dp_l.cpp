#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[3005][3005];
signed main(){
    int n;
    cin >> n;
    vector<int>v(n+1);
    for(int i = 1; i <= n; ++i)cin >> v[i];
    for(int i = n; i >= 1; --i){
        for(int j = i; j <= n; ++j){
            if(i == j)dp[i][j] = v[i];
            else dp[i][j] = max(v[i] - dp[i+1][j],v[j] - dp[i][j-1]);
        }
    }
    cout << dp[1][n] << '\n';
}