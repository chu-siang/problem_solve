#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
vector<int>apple(MAXN);
vector<int>G[MAXN];
int root[MAXN];
bool visit[MAXN];
int cnt = 0;
void dfs(int t){
    if(!G[t].size()){
        cnt+=abs(1-apple[t]);
        apple[root[t]]+=(apple[t]-1);
        apple[t] = 1;
        return;
    }
    for(auto i:G[t]){
        if(G[i].size()){
            dfs(i);
        }
        cnt+=abs(1-apple[i]);
        apple[root[i]]+=(apple[i]-1);
        apple[i] = 1;
    }
    return;
}

signed main(){
    int n;
    cin >> n;
    memset(root,-1,sizeof(root));
    for(int i = 0; i < n; i++){
        int v,d,t;
        cin >> v >> apple[v];
        cin >> t;
        for(int j = 0; j < t; j++){
            cin >> d;
            G[v].push_back(d);
            root[d] = v;
        }
    }
    int start = 0;
    for(int i = 1; i <= n; i++){
        if(root[i] == -1){
            start = i;
            break;
        }
    }
    dfs(start);
    cout << cnt << '\n';
}
