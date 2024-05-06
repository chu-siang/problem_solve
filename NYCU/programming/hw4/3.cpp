//11875
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin >> t;
    for(int c = 1; c <= t; c++){
        int n;
        cin >> n;
        vector<ll>v(n);
        for(int i = 0; i < n; i++)cin >> v[i];
        sort(v.begin(),v.end());
        cout <<"Case " << c <<": "<< v[n/2] << '\n';
    }
}