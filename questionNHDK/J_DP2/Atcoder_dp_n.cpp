#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[405][405];
signed main(){
    int n;
    cin >> n;
    int arr[405] = {0};
    int pre[405] = {0};
    for(int i = 1; i <= n; ++i)cin >> arr[i];
    for(int i = 1; i <= n; ++i){
        pre[i] = arr[i]+pre[i-1];
    }
    for(int i = 0; i < 405; ++i){
        for(int j = 0; j < 405; ++j){
            dp[i][j] = 1e15;
        }
    }
    for(int i = 0; i <= n; i++)dp[i][i] = 0;
    for(int l = n; l >= 1; --l){
        for(int r = l; r <= n; ++r){
            for(int k = l; k < r; ++k)
                dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]+pre[r]-pre[l-1]);
        }
    }
    cout <<dp[1][n] << '\n';
}