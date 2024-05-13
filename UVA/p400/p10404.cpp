#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;
int a[15];
bool dp[MAXN];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    while(cin >> n){
        cin >> m;
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < m; i++)cin >> a[i];
        for(int i = 1; i <= n; i++){
            dp[i] = 0;
            for(int j = 0; j < m; j++){
                if(i - a[j] >= 0 && dp[i-a[j]]== 0){
                    dp[i] = 1;
                }
            }
        }
        cout << (dp[n]?"Stan ": "Ollie ") << "wins\n";
    }
}