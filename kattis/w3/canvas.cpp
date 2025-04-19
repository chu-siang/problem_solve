#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<int,vector<int>,greater<int>>pq;
        int sum = 0;
        vector<int>v(n);
        for(int i = 0; i < n; ++i){
            cin >> v[i];
            pq.emplace(v[i]);
        }
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            sum += a+b;
            pq.emplace(a+b);
        }
        cout << sum << '\n';
    }
}