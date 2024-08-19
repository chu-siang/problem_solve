#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;

vector<int>G[MAXN];
vector<int>ans,from;
void bfs(int n){
    queue<int>q;
    q.push(1);
    from.resize(n+1);
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int e : G[now]){
            if(from[e] == 0){
                from[e] = now;
                q.push(e);
            }
        }
    }
    if(from[n] == 0){
        cout << "IMPOSSIBLE\n";
        return;
    }
    int now = n;
    while(now != 1){
        ans.push_back(now);
        now = from[now];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(auto i:ans){
        cout << i << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m; 
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs(n);
}