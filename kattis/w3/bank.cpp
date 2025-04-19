#include<bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n, t;
    cin >> n >> t; 
    vector<vector<int>>v(t, vector<int>());
    int a,b;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        v[b].emplace_back(a);
    }
    priority_queue<int,vector<int>>pq;
    int sum = 0;
    for(int i = t-1; i >= 0; --i){
        for(int j : v[i]){
            pq.emplace(j);
        }
        if(pq.size()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << '\n';
}