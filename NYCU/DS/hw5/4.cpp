//uva341
#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<vector<pair<int,int>>>adj(n+1,vector<pair<int,int>>());
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        while(m--){
            int v,w;
            cin >> v >> w;
            adj[i].push_back({v,w});
        }
    }
    vector<int>dis(n+1,INT_MAX);
    vector<int>parent(n+1,-1);
    int s,t;
    cin >> s >> t;
    dis[s] = 0;
    pq.push({0,s});
    while(pq.size()){
        int u = pq.top().second;
        pq.pop();
        for(auto i : adj[u]){
            int v = i.first;
            int weight = i.second;
            if(dis[v] > dis[u] + weight){
                dis[v] = dis[u] + weight;
                pq.push({dis[v],v});
                parent[v] = u;
            } 
        }
    }
    vector<int>ans;
    for(int x = t; x != s; x = parent[x])ans.push_back(x);
    ans.push_back(s);
    reverse(ans.begin(),ans.end());
    cout << "Path =";
    for(int i = 0; i < ans.size(); i++)cout << ' ' << ans[i];
    cout << "; " << dis[t] << " second delay\n";
}