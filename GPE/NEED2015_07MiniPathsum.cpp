#include<bits/stdc++.h>
using namespace std;
int r,c;
signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> r >> c;
        vector<vector<int>>mp(r,vector<int>(c,0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> mp[i][j];
            }
        }
        vector<vector<int>>dp(r,vector<int>(c,0));
        dp[0][0] = mp[0][0];
        for(int i = 1; i < r; i++){
            dp[i][0] = dp[i-1][0] + mp[i][0];
        }
        for(int i = 1; i < c; i++){
            dp[0][i] = dp[0][i-1] + mp[0][i];
        }
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+mp[i][j];
            }
        }
        cout << dp[r-1][c-1] << '\n';
    }
}