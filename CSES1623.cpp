#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> v(n+5);
    cin >> n;
    ll t = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        t+=v[i];
    }
    ll ans = 1e18;

    for(int i = 0; i<( 1 << n ); i++){
        ll num = i, index = 0, total = 0;
        while(num!=0){
            if((num&1) == 1){
                total += v[index];
            }
            index++;
            num >>= 1;
        }
        ll total2 = t - total;
        ans = min(ans,abs(total-total2));
    }
    cout << ans << '\n';
}       