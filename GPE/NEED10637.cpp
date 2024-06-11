#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;
double dp[105][15];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    while(cin >> k >> n){
        memset(dp,0,sizeof(dp));
        for(int i =1; i <= k+1; i++)dp[1][i] = 1.0/(double)(k+1);
        for(int i =2; i <= n; i++){
            for(int j = 1; j <= k+1; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])/(double)(k+1);
            }
        }
        double ans =0 ;
        for(int i = 1;i <= k+1; i++)ans+=dp[n][i];
        ans*=100;
        cout << fixed << setprecision(5) << ans << '\n';
    }

}