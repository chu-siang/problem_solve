#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+5;
vector<int>G[MAXN];
bitset<MAXN>vis;
int color[MAXN];

bool dfs(int i){
    vis[i] = 1;
    bool legal = true;
    for(int e : G[i]){
        if(color[e] == color[i]){
            return false;
        }
        if(!vis[e]){
            color[e] = 1 + (1 == color[i]);
            legal &= dfs(e);
        }
    }
    return legal;
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
    bool legal = true;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            color[i] = 1;
            legal &= dfs(i);
        }
        if(!legal){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++)cout << color[i] << ' ';
}