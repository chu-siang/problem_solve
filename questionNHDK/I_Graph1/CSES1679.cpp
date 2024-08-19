#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+5;
const int INF = 1e9;
vector<int>G[MAXN];
vector<int>topo;
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
        topo.push_back(now);
        for(int e : G[now]){
            in[e]--;
            if(!in[e]){
                q.push(e);
                in[e] = INF;
            }
        }
    }
    if(topo.size() == n){
        for(int i : topo)cout << i << ' ';
    }else{
        cout << "IMPOSSIBLE";
    }
}
/*
//dfs
int visit[MAXN];

//dfs
bool dfs(int i){
    visit[i] = 2;
    bool legal = true;
    for(int e : G[i]){
        if(!visit[e]){
            legal &= dfs(e);
        }
        if(visit[e] == 2){
            return false;
        }
    }
    topo.push_back(i);
    visit[i] = 1;
    return legal;
}

signed main(){
    int n,m;
    cin >> n >> m;
    int a,b;
    bool legal = true;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            legal &= dfs(i);
        }
    }
    if(!legal){
        cout << "IMPOSSIBLE";
        return 0;
    }
    reverse(topo.begin(),topo.end());
    for(auto i : topo)cout << i << ' ';
}
*/
