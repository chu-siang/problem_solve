#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    while(cin >> n,n){
        map<int,int>mp;
        mp[n]++;
        int cnt = 0;
        while(mp[n] < 2){
            n*=n;
            n%=1000000;
            n/=100;
            mp[n]++;
            cnt++;
        }
        cout << cnt << '\n';
    }
}