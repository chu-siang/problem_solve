//11388
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
    ll t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(b%a == 0){
            cout << a << " " << b;
            cout << '\n';
        }else {
            cout << -1 << '\n'; 
        }
    }
}
/*A 183-5724 17 58 18 04*/