#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;
int dp[1005][1005];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s1,s2;
    bool flag = false;
    while(getline(cin,s1)&&getline(cin,s2)){
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= s1.length(); i++){
            for(int j = 1; j <= s2.length(); j++){
                if(s1[i-1] == s2[j-1])dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << dp[s1.size()][s2.size()] << '\n';
    }

}