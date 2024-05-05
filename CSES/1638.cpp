#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 1e4+5;
int dp[MAXN][MAXN];
char c[MAXN][MAXN];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> c[i][j];
    }
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(c[i][j] != '*'){
                dp[i][j] += (dp[i][j-1]+dp[i-1][j])%MOD;
            }else{
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n][n] << '\n';
}