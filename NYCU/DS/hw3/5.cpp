#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mx = -1e9,mn = 1e9;
    int sum = 0;
    int curmx = -1e9,curmn = 1e9;
    for(int i = 0; i < n; i++){
        curmx = max(curmx+a[i],a[i]);
        curmn = min(curmn+a[i],a[i]);
        sum += a[i];
        mx = max(mx,curmx);
        mn = min(mn,curmn);
    }
    cout << (mx > 0 ? max(mx,sum - mn) : mx) << '\n';
}
