#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int t;
    cin >> t;
    string s;
    getline(cin,s);
    while(t--){
        getline(cin,s);
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        stringstream ss(s1);
        stringstream ss2(s2);
        ll num,mx = 0;
        vector<ll>v;
        while(ss >> num){
            if(num > mx) mx = num; 
            v.push_back(num);
        }
        vector<pair<ll,string>>ans;
        ll i = 0;
        while(ss2 >> s){
            ans.push_back({v[i],s});
            i++;
        }
        sort(ans.begin(),ans.end());
        for(int i = 0; i < mx; i++)cout << ans[i].second <<"\n";
        if(t)cout << '\n';
        ss.clear();
        ss.str("");
    }
}
/*
3 
yes
yes
Casematters
casematters
no space     please
nospaceplease
*/