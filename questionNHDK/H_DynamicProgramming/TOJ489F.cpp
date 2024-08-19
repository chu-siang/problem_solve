#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5+5;
int dp[MAXN],a[MAXN],pre[MAXN];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    while(cin >> n >> k){
        pre[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            pre[i] = pre[i-1]+a[i];
        }
        for(int i = 0; i <= n; i++){
            if(i == k)dp[i] = pre[k];
            else if(i < k)dp[i] = 0;
            else{
                dp[i] = max(dp[i-k-1]+pre[i]-pre[i-k],dp[i-1]);
            }
        }
        cout << dp[n] << '\n';
    }

}