#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN];


signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a+n);
    int ans = n;
    for(int i = 0; i < n; ++i){
        ans = min(ans, n - 1 - i + a[i]);
    }
    cout << ans << '\n';
    
}