#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    while(cin >> n,n){
        ll x1 = -1e9, x2 = 1e9, y1 = -1e9, y2 = 1e9, z1 = -1e9, z2 = 1e9;
        ll x, y, z, d;
        while(n--){
            cin >> x >> y >> z >> d;
            x1 = max(x1, x);
            x2 = min(x2, x + d);
            y1 = max(y1, y);
            y2 = min(y2, y + d);
            z1 = max(z1, z);
            z2 = min(z2, z + d);
        }
        if(x1 >= x2 || y1 >= y2 || z1 >= z2) cout << 0 << '\n';
        else cout << (x2 - x1) *(y2 - y1) *(z2 - z1) << '\n';
    }
}