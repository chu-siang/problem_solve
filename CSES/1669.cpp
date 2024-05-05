#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+5;
vector<int>G[MAXN];
vector<int>ans;
int vis[MAXN];
stack<int>path;
int n,m;

void dfs(int i,int pre){
    vis[i] = 2;
    path.push(i);
    for(int e : G[i]){
        if(!vis[e]){
            dfs(e,i);
        }
        if(vis[e] == 2 && e!=pre && ans.empty()){
            ans.push_back(e);
            while(path.size()){
                ans.push_back(path.top());
                if(path.top() == e){
                    break;
                }
                path.pop();
            }
            reverse(ans.begin(),ans.end());
            return;
        }
    }
    vis[i] = 1;
	
	if (path.size())
		path.pop();
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i,i);
        }
    }
    if(ans.empty()){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans.size() << '\n';
    for(auto i : ans)cout << i << ' ';
}