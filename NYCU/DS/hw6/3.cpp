#include<bits/stdc++.h>
using namespace std;

signed main(){
    map<int,int>mp;
    int n;
    bool flag = false;
    while(cin >> n){
        mp[n]++;
        if(mp[n]>=2)flag = true;
    }
    if(flag)cout << "true\n";
    else cout << "false\n";
}