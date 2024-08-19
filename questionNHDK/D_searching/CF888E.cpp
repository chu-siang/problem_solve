#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[43];
ll l = 0,r = 0;
ll aa[2<<20],bb[2<<20];
void sub1(int x,ll sum){
    if(x == n/2+1){
        aa[l++] = sum;
        return;
    }
    sub1(x+1,(sum + a[x])%m);
    sub1(x+1,sum);
}
void sub2(int x,ll sum){
    if(x == n+1){
        bb[r++] = sum;
        return;
    }
    sub2(x+1,(sum+a[x])%m);
    sub2(x+1,sum);
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sub1(1,0);
    sub2(n/2+1,0);
    ll ans = 0;
    sort(aa,aa+l);
    sort(bb,bb+r);
    for(int i = 0; i < l; i++){
        ll x = m - aa[i]-1;
        ll cnt = upper_bound(bb,bb+r,x)-bb-1;
        if(cnt != 0)ans = max(ans,aa[i]+bb[cnt]);
        else ans = max(ans,aa[i]);
    }
    cout << ans << '\n';
}