#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+5;
const int INF = 3e6;
int dp[MAXN];
vector<int>G[MAXN];
bitset<MAXN>vis;
int in[MAXN];
signed main(){
    int n,m;
    cin >> n >> m;
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }
    queue<int>q;
    for(int i = 1; i <= n; i++){
        if(!in[i]){
            q.push(i);
            in[i] = INF;
        }
    }
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int e : G[now]){
            in[e]--;
            dp[e] = max(dp[e],dp[now]+1);
            if(!in[e]){
                q.push(e);
                in[e] = INF;
            }
        }
    }
    cout << *max_element(dp+1,dp+n+1);
}