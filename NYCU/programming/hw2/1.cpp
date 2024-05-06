#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    ll s,d;
    cin >> t;
    while(t--){
        cin >> s >> d;
        if(d > s  || ((s+d)&1)){
            cout << "impossible\n";
            continue;
        } 
        ll c = (s+d)/2;
        ll e = s - c;
        cout << c << ' ' << e << '\n';
    }
}