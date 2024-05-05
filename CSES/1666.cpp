#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+5;
vector<int>G[MAXN];
bool visit[MAXN];

void dfs(int v){
    if(visit[v])return;
    visit[v] = 1;
    for(int e : G[v]){
        dfs(e);
    }
}

signed main(){
    int n,m;
    cin >> n >> m;
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    vector<pair<int,int>>ans;
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            ans.push_back({1,i});
            dfs(i);
        }
    }
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i.first <<' ' << i.second << '\n';
    }
}