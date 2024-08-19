#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+5;
const int INF = 0x3f3f3f3f3f3f;
int dp[MAXN];
vector<int>G[MAXN];
int price[MAXN];
int in[MAXN];
signed main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }
    queue<int>q;
    for(int i = 1; i <= n; i++){
        dp[i] = INF;
        if(!in[i]){
            q.push(i);
            in[i] = INF;
        }
    }
    int ans = -INF;
    while(q.size()){
        int now = q.front();
        q.pop();
        ans = max(ans,price[now] - dp[now]);
        dp[now] = min(dp[now],price[now]);
        for(int e : G[now]){
            in[e]--;
            dp[e] = min(dp[now],dp[e]);
            if(!in[e]){
                q.push(e);
                in[e] = INF;
            }
        }
    }
    cout << ans << '\n';
}