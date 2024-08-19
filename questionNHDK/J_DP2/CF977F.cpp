#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
map<int,int>dp;
int pos[MAXN];
signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    int ans = 0;
    int lst = 0;
    for(int i = 0; i < n; i++){
        int x = a[i];
        dp[x] = dp[x-1] + 1;
        if(ans < dp[x]){
            ans = dp[x];
            lst = x;
        }
    }
    vector<int>tmp;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == lst){
            tmp.push_back(i+1);
            lst--;
        }
    }
    cout << ans << '\n';
    reverse(tmp.begin(),tmp.end());
    for(auto i : tmp)cout << i << ' ';

}