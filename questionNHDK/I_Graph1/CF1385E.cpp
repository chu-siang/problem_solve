#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+5; 
vector<vector<int>>G;
vector<pair<int,int>>edge;
int pos[MAXN];
vector<int>topo;
bitset<MAXN>vis;

void dfs(int i){
    vis[i] = 1;
    for(auto e : G[i]){
        if(!vis[e]){
            dfs(e);
        }
    }
    topo.push_back(i);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    int n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int t,a,b;
        G = vector<vector<int>>(n+1);
        edge.clear();
        topo.clear();
        memset(pos,0,sizeof(pos));
        vis = 0;
        for(int i = 0; i < m; i++){
            cin >> t >> a >> b;
            if(t)G[a].push_back(b);
            edge.push_back({a,b});
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        reverse(topo.begin(),topo.end());   
        for(int i = 1; i <= n; i++){
            pos[topo[i-1]] = i;
        }
        bool flag = false;
        for(int i = 1; i <= n; i++){
            for(int j : G[i]){
                if(pos[i] > pos[j])flag = true;
            }
        }
        if(flag){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < m; i++){
            a = edge[i].first,b = edge[i].second;
            if(pos[a] > pos[b]){
                cout << b << ' ' << a << '\n';
            }else{
                cout << a  << ' '<< b  << '\n';
            }
        }
    }
}