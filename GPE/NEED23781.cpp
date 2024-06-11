#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e4+5;
int c[6] = {1,2,4,10,20,40};
int change[MAXN];
int num[6];
int dp[MAXN];
signed main(){
    memset(change,0,sizeof(change));
    for(int i = 1; i < MAXN; i++){
        int cnt = 0;
        int tmp = i;
        for(int j = 5; j >= 0; j--){
            cnt += (tmp/c[j]);
            tmp -= (c[j])*(tmp/c[j]);
            if(tmp == 0)break;
        }
        change[i] = cnt;
    }
    double m;
    while(cin >> num[0]){
        for(int i = 1; i < 6; i++)cin >> num[i];
        if(num[0]+num[1]+num[2]+num[3]+num[4]+num[5] == 0)return 0;
        cin >> m;
        int x = (m+0.005)*100;
        x/=5;
        fill(dp,dp+MAXN,1e9);
        dp[0] = 0;
        int tot = 0;
        for(int i = 0; i < 6; i++)tot+=(num[i]*c[i]);
        for(int i = 0; i < 6; i++){
            for(int j = 1; j <= num[i]; j++){
                for(int k = tot; k >= j*c[i]; k--){
                    dp[k] = min(dp[k],dp[k-c[i]*j]+j);
                }
            }
        }
        int ans = dp[x];
        for(int i = x+1; i <= 100; i++){
            ans = min(ans,dp[i]+change[i-x]);
        }
        cout <<setw(3) << setfill(' ') <<  ans << '\n';
    }
}