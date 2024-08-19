#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 5e2+5;

int dp[MAXN][MAXN];

pair<int,int>pre[MAXN][MAXN];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,l,k;
    cin >> n >> l >> k;
    vector<int>a(n+1,0);//路標
    vector<int>b(n+1,0);//速度
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];
    

    a[n] = l;//幫終點開個點,方便計算
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = (int)1e18;
        }
    }
    for(int i = 0; i <= k; i++)dp[0][i] = 0;
    //dp[i][j]  :拆 j 個 告示牌 到 i 個告示牌所需花費的最短時間
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            for(int p = i-1; p >= 0; p--){
                if(j - (i - p - 1) < 0)break;
                dp[i][j] = min(dp[i][j],dp[p][j - (i - p -1)]+b[p]*(a[i]-a[p]));
            }
        }
    }
    cout << *min_element(dp[n],dp[n]+k+1) << '\n';
}

