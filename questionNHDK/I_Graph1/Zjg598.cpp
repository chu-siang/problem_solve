#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e4+5;
int n,m;

vector<pair<int,int>>G[MAXN];
int color[MAXN];
bitset<MAXN>illegal,vis;

bool dfs(int i,int mid){
    vis[i] = 1;
    bool legal = true;
    for(auto e : G[i]){
        if(illegal[e.second] || e.second > mid)continue;
        else if(vis[e.first] && color[e.first] == color[i]){
            return false;
        }
        if(!vis[e.first]){
            color[e.first] = 1 + (color[i] == 1);
            legal &= dfs(e.first,mid);
        }
    }
    return legal;
}

bool check(int mid){
    vis.reset();
    memset(color,0,sizeof(color));
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            color[i] = 1;
            if(!dfs(i,mid)){
                return false;
            }
        }
    }
    return true;
}


signed main(){
    cin >> n >> m;
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back({b,0});
        G[b].push_back({a,0});
    }
    int p,k;
    cin >> p >> k;
    for(int i = 1; i <= p; i++){
        for(int j = 0; j < k; j++){
            cin >> a >> b;
            G[a].push_back({b,i});
            G[b].push_back({a,i});
        }
    }
    vector<int>ans;
    for(int i = 0; i < 3 && !check(p); i++){
        int l = 0, r = p;
        while(r - l > 1){
            int mid = r+l>>1;
            if(check(mid)){
                l = mid;
            }else r = mid;
        }
        if(r > 0){
            illegal[r] = 1;
            ans.push_back(r);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto i : ans)cout << i << '\n';
}