#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    int t;
    map<int,int>mp;
    for(int i =0 ;i < n; i++){
        cin >> t;
        mp[t]++;
    }
    int cnt = 0;
    for(auto i:mp){
        if(i.second == 1){
            cnt = -1;
            break;
        }
        cnt+=i.second/3;
        if(i.second%3)cnt++;
    }
    cout << cnt << '\n';
}