//uva10346
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,k;
    while(cin >> n >> k){
        ll ans = 0;
        ll tmp = 0;
        while(n){
            ans += n;
            tmp += (n % k);
            n/=k;
        }
        while(tmp >= k){
            ans += (tmp/k);
            tmp = (tmp/k) + (tmp % k);
        }
        cout << ans << '\n';
    }
}
