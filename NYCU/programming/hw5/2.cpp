//10018
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll r(ll a){
    ll t = 0;
    while(a){
        t*=10;
        t += a%10;
        a/=10;
    }
    return t;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll p = 0;
        do{
            p++;
            n += r(n);
        } while (r(n) != n);
        cout << p << ' ' << n << '\n';
    }
}
/*A 183-5724 17 58 18 04*/