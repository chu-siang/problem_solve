#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
using namespace std;
int s,d,n,m;
int w[505][505];
vector<int>adj[505];
vector<pair<int,int>>visPath;

int dij(){
    bool vis[505] = {0};
    int dis[505],p[505];
    fill(dis,dis+505,INF);
    int u;

    dis[s] = 0,p[s] = s;
    for(int i = 0; i < n; i++){
        u = -1;
        int mndis = INF;
        for(int j = 0; j < n; j++){
            if(!vis[j]&& dis[j] < mndis){
                u = j;
                mndis = dis[j];
            }
        }
        if(u == -1)break;
        vis[u] = true;
        for(auto v:adj[u]){
            if(dis[v] >= dis[u] + w[u][v]){
                if(find(visPath.begin(),visPath.end(),make_pair(u,v))!=visPath.end()){
                    continue;
                }
                p[v] = u;
                dis[v] = dis[u] + w[u][v];
            }
        }
    }
    if(vis[d]){
        for(int u = d; u!=s; u=p[u]){
            visPath.push_back({p[u],u});
        }
    }
    return dis[d];
}
signed main(){
    while(cin >> n >> m){
        if(n == 0&& m == 0)break;
        for(int i = 0; i < n;++i)adj[i].clear();
        visPath.clear();
        cin >> s >> d;
        for(int i = 0; i < m; i++){
            int u,v,wei;
            cin >> u >> v >> wei;
            adj[u].push_back(v);
            w[u][v] = wei;
        }
        int minDis = dij(),sec;
        bool flag = true;
        while(true){
            sec = dij();
            if(sec == INF){
                flag = false;
                break;
            }
            if(sec != minDis){
                break;
            }
        }
        if(flag)cout << sec << '\n';
        else cout << -1 << '\n';
    }
}