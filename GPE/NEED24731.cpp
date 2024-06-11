#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e4+5;
vector<pair<int,int>>G[MAXN];
int ans = 0;
int dfs(int from,int to){
    int lmax = 0,len = 0;
    for(auto t : G[to]){
        if(t.first != from){
            len = t.second+dfs(to,t.first);
            ans = max(ans,len+lmax);
            lmax = max(len,lmax);
        }
    }
    return lmax;
}

signed main(){
    int a,b,l;
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    while(getline(cin,s)){
        if(s == ""){
            dfs(0,1);
            cout << ans << '\n';
            for(int i = 0; i < 10001; i++)G[i].clear();
            ans = 0;
            continue;
        }
        stringstream ss(s);
        ss >> a >> b >> l;
        G[a].push_back({b,l});
        G[b].push_back({a,l});
        ss.clear();
        ss.str("");
    }
    dfs(0,1);
    cout << ans << '\n';
}