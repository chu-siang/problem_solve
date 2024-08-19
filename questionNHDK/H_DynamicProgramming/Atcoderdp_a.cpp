#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5+5;
int dp[MAXN];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<int>v(n+1);
    for(int i = 1; i <= n; i++)cin >> v[i];
    dp[1] = 0, dp[2] = abs(v[2] - v[1]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i-1] + abs(v[i-1] - v[i]),dp[i-2]+abs(v[i-2]-v[i]));
    }
    cout << dp[n] << '\n';
}