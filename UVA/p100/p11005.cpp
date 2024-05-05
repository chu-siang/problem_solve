#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 105;

int main(){
    ll t;
    cin >> t;
    for(int Case = 1; Case <= t; Case++){
        if(Case > 1) cout << '\n';
        cout <<"Case " << Case << ":\n";
        map<ll,ll>mp;
        ll cost;
        for(ll i = 0; i < 36; i++){
            cin >> cost;
            mp[i] = cost;
        }
        
        ll q,n,ask;
        ll ans[37] = {0};
        cin >> q;
        while(q--){
            cin >> ask;
            cout << "Cheapest base(s) for number " << ask << ":";
            ll mn = 2e9+5;
            for(int i = 2; i <= 36; i++){
                cost = 0;
                n = ask;
                while(n){
                    cost += mp[n%i];
                    n/=i;
                }
                ans[i] = cost;
                mn = min(mn,cost);
            }
            for(int i = 2; i <= 36; i++){
                if(ans[i] == mn) cout << ' ' << i;
            }
            cout << '\n';
        }
    }
    return 0;
}