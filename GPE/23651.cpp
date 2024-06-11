#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN],dp[MAXN];
signed main(){
    int n;
    while(cin >> n,n){
        for(int i = 1; i <= n; i++)cin >>a[i];
        int win = -1e9;
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; i++){
            dp[i] = max(dp[i],dp[i-1]+a[i]);
            win = max(dp[i],win);
        }
        if(win > 0)cout << "The maximum winning streak is " << win <<".\n";
        else cout << "Losing streak.\n";
    }
}