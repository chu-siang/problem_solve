#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int l;
    while(cin >> l,l){
        int n;
        cin >> n;
        n++;
        int a[55] = {0};
        a[n] = l;
        int dp[55][55];
        memset(dp,1e9,sizeof(dp));
        dp[0][1] = 0;
        for(int i = 1; i < n; i++){
            cin >> a[i];
            dp[i][i+1] = 0;
        }
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= n-i; j++){
                int k = j + i;
                int minn = 1e10;
                for(int e = j+1; e < k; e++){
                    minn = min(minn,dp[j][e]+dp[e][k]);
                }
                dp[j][k] = minn + a[k] - a[j];
            }
        }
        cout << "The minimum cutting is " << dp[0][n] << ".\n";
    }
}