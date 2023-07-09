#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 10;

ll a[MAXN] = {0}, b[MAXN] ={0};
ll pre[MAXN] = {0},suf[MAXN] = {0};

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 2; i <= n * 2; i+=2) cin >> a[i];
    for(int i = 2; i <= n * 2; i+=2){
        cin >> b[i];
        ans += a[i] * b[i];
    }

    int m = 2 * n;
    for(int i = 1; i <= m; i++) pre[i] = pre[i-1]+a[i] * b[i];
    for(int i = m; i >= 1; i--) suf[i] = suf[i+1]+a[i] * b[i];

    for(int i = 2; i < m; i++){
        ll res = a[i] * b[i];
        int l = i-1, r = i+1;
        while(l >= 1 &&  r <= m){
            res += a[l] * b[r];
            res += a[r] * b[l];
            ans = max(ans, res +  pre[l-1] + sur[r+1]);
        }
    }
    cout << ans << endl;
    return 0;
}