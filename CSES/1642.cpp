#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n;
    ll x;
    while(cin >> n >> x){
        vector<ll>v(n);
        map<int,pair<int,int>>mp;
        for(ll i = 0; i < n; i++){
            cin >> v[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(mp.count(x - v[i] -v[j])){
                    cout << i + 1 << ' ' << j + 1<< ' ' << mp[x-v[i]-v[j]].first+1 << ' ' << mp[x-v[i]-v[j]].second+1;
                    return 0;
                }
            }
            for(int j = 0; j < i; j++){
                mp[v[i] + v[j]] = {i,j};
            }
        }
        cout <<"IMPOSSIBLE\n";
    }
}