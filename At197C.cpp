#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200005;
ll a[MAXN];
ll b[MAXN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll mn = 1e18;
    for(ll i = 0; i < (1 << n); i++){
        ll tmp = 0;
        ll res = 0;
        for(ll j = 0; j <= n; j++){
            if(j < n) tmp |= a[j];
            if(j == n || (i >> j) & 1){
                res ^= tmp;
                tmp = 0;
            }
        }
        mn = min(mn,res);
    }
    cout << mn << '\n';

}