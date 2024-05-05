#include<iostream>
#include<cmath>
#define ll long long 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll a, b, c,mx;
    ll ans = -1e9;
    for(a = 0; a <= n; a++){
        for(b = 0; b <= n-a; b++ ){
            c = n - a - b;
            mx = 2022 + abs(b-c) + a*b + b*c + c*c -abs(b*b-a*a);
            ans = max(ans,mx);
        }
    }
    cout << ans;
}