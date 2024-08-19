#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 5e7;
vector<int>G[MAXN];
vector<int>topo;
int in[MAXN];

signed main(){
    int n,m;
    int a,b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i = 1; i <= n; i++){
        if(!in[i]){
            pq.push(i);
            in[i] = INF;
        }
    }
    while(pq.size() > 0){
        int now = pq.top();
        pq.pop();
        topo.push_back(now);
        for(int e : G[now]){
            in[e]--;
            if(!in[e]){
                pq.push(e);
                in[e] = INF;
            }
        }
    }
    if(topo.size() != n){
        cout << "-1\n";
        return 0;
    }
    for(auto i : topo)cout << i << ' ';
}