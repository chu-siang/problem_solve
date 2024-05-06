//Bank queue
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e4+5;

signed main(){
    int n,t;
    cin >> n >> t;
    map<int,vector<int>>mp;
    int a,b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        mp[b].push_back(a);
    }
    priority_queue<int,vector<int>>pq;
    int sum = 0;
    for(int i = t; i >= 0; i--){
        for(int j : mp[i]){
            pq.push(j);
        }
        if(pq.size()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << '\n';
}