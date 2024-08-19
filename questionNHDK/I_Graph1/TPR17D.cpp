#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5e3+5;
int color[2][MAXN];
vector<int>G[MAXN];
int cnt,diff;

bool dfs(int i){
    bool legal = true;
    cnt++;
    diff += color[0][i] != color[1][i];
    
    for(int e : G[i]){
        if(color[1][i] == color[1][e]){
            return false;
        }
        if(!color[1][e]){
            color[1][e] = 1 + (color[1][i] == 1);
            legal &= dfs(e);
        }
    }
    return legal;
}

signed main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> color[0][i];
        color[0][i]++;
    }
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bool legal =true;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cnt = 0,diff = 0;
        if(!color[1][i]){
            color[1][i] = 1;
            legal &= dfs(i);
        }
        if(!legal){
            cout << "-1";
            return 0;
        }
        ans += min(diff,cnt - diff);
    }
    cout << ans << '\n';
    return 0;
}