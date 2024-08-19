#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+5;
int a[MAXN];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin >> n >> k;
    int ans = 0;
    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = a[i-1]+x;
    }
    sort(a+1,a+n);
    ans = a[n]*k;
    for(int i = 1; i < k; i++){
        ans -= a[i];
    }
    cout << ans;
}