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
        map<int,int>mp;
        for(ll i = 0; i < n; i++){
            cin >> v[i];
            mp[v[i]] = i+1;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(mp.count(x - v[i] -v[j])){
                    if(i+1 == mp[x-v[i]-v[j]] || j+1 == mp[x-v[i]-v[j]])continue;
                    cout << i + 1 << ' ' << j + 1<< ' ' << mp[x-v[i]-v[j]];
                    return 0;
                }
            }
        }
        cout <<"IMPOSSIBLE\n";
    }
}