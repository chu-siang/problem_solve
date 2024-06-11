#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n,m;
    cin >> n >> m;
    map<string,int>mp;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        int n;
        cin >> s >> n;
        cin.ignore();
        mp[s] = n;
    }
    string s;
    while(m--){
        int ans = 0;
        while(cin >> s){
            if(s == ".")break;
            if(mp.count(s))ans+=mp[s];
        }
        cout << ans << '\n';
    }
}