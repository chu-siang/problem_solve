#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5+5;
vector<int>G[MAXN];
int in[MAXN];
int dp[MAXN];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k,a;
        for(int i = 0; i <= n; i++)G[i].clear();
        for(int i = 1; i <= n; i++){
            dp[i] = 0;
            cin >> in[i];
            for(int j = 0; j < in[i]; j++){
                cin >> a;
                G[a].push_back(i);
            }
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 1; i <= n; i++){
            if(!in[i]){
                dp[i] = 1;
                in[i] = INF;
                pq.push(i);
            }
        }
        int cnt = 0;
        vector<int>topo;
        while(pq.size()){
            int now = pq.top();
            pq.pop();
            cnt++;
            for(int e : G[now]){
                dp[e] = max(dp[e],dp[now] + (now > e));
                in[e]--;
                if(!in[e]){
                    pq.push(e);
                    in[e] = INF;
                }
            }
        }
        if(cnt < n){
            cout << "-1\n";
            continue;
        }
        cout << *max_element(dp+1,dp+1+n) << '\n';
    }
}