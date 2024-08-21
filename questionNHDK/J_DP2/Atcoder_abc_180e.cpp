#include<bits/stdc++.h>
#define int long long
#define dis(i,j)  (abs(a[i] - a[j]) + abs(b[i] - b[j]) +max(0LL,c[i] - c[j]))
using namespace std;
const int M = 20, N = (1 << 17)+5;
int a[M], b[M], c[M],dp[N][M];



signed main(){
    int n;
    cin >> n;
    int K = (1 << n);
    for(int i = 1; i <= n; ++i)cin >> a[i] >> b[i] >> c[i];
    memset(dp,0x3f,sizeof(dp));
    dp[1][1] = 0;
    for(int i = 0; i < K; ++i){
        for(int j = 1; j <= n; ++j){
            if(i & (1 << (j-1))){
                for(int k = 1; k <= n; ++k){
                    if(j != k)
                        dp[i|(1 << (k-1))][k] = min(dp[i|(1 << (k-1))][k],dp[i][j] + dis(j,k));
                }
            }
        }
    }
    cout << dp[K-1][1];
}