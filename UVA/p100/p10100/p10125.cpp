//uva 10125
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    while(cin >> n,n){
        vector<int>v(n);
        map<int,pair<int,int>>mp;  
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int ans = -1e9;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                mp[v[i]+v[j]] = {i,j};
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i!=j && mp.count(v[i]-v[j])){
                    auto t = mp[v[i]-v[j]];
                    if(t.first!=i && t.second!= i && t.first != j && t.second!= j){
                        ans = max(ans,v[i]);
                    }
                }
            }
        }
        if(ans!=-1e9)cout << ans << '\n';
        else cout << "no solution\n";
    }
}