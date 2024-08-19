#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 3e3+5;

int dp[MAXN][MAXN];

pair<int,int>pre[MAXN][MAXN];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s,t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < t.size(); j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                pre[i+1][j+1] = {i,j};
            }else if(dp[i+1][j] > dp[i][j+1]){
                dp[i+1][j+1] = dp[i+1][j];
                pre[i+1][j+1] =  {i+1,j};
            }else{
                dp[i+1][j+1] = dp[i][j+1];
                pre[i+1][j+1] = {i,j+1};
            }
        }
    }
    int index1 = s.size(),index2 = t.size();
    string ans = "";
    while(index1 >= 1 && index2 >= 1){
        if(pre[index1][index2] == make_pair(index1-1,index2-1)){
            ans += s[index1-1];
        }
        pair<int,int> u  = pre[index1][index2];
        index1 = u.first;
        index2 = u.second;
    }
    for(int i = ans.size()-1; i >= 0; i--)cout << ans[i];
}

