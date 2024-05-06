//11332
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll n){
    if(n < 10) return n;
    ll t = 0;
    while(n){
        t+=n%10;
        n/=10;
    }
    return f(t);
}


int main(){
    ll n;
    while(cin >> n,n){
        cout << f(n) << '\n';
    }
}