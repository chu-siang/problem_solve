#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5+5;
int a[MAXN],b[MAXN];

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;//n <= m;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        int ans = 0;
        sort(a,a+n);
        sort(b,b+m,greater<int>());
        for(int i = 0; i < n; i++)ans += abs(a[i]-b[i]);
        int maxn = ans;
        for(int i = n-1; i >= 0; i--){
            ans -= abs(a[i]-b[i]);
            ans += abs(a[i]-b[i-n+m]);
            maxn = max(ans,maxn);
        }
        cout << maxn << '\n';
    }
}