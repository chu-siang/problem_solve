#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e7 + 10;

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

/*
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<ll>a(n),b(n);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    
    vector<ll>pre(n+1,0);
    for(int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + a[i] * b[i];
    ll ans = pre[n];
    for(int c = 0; c < n; c++){
        ll cur = a[c] * b[c];
        for(int l = c-1, r = c+1; l >= 0 && r < n; l--, r++){
            cur += a[r] * b[l];
            cur += a[l] * b[r];
            ans = max(ans, cur + pre[l] + (pre[n] - pre[r + 1]));
        }
        cur = 0;
        for(int l = c, r = c+1; l >= 0 && r < n; l--, r++){
            cur += a[r] * b[l];
            cur += a[l] * b[r];
            ans = max(ans, cur + pre[l] + (pre[n] - pre[r + 1]));
        }
    }
    cout << ans << '\n';
    return 0;
}

*/