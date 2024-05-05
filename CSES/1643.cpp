#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5+5;
int a[MAXN];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >>a[i];
    int mxsub = -1e18;
    int tmpmx = -1e18;
    for(int i = 0; i < n; i++){
        tmpmx = max(a[i],a[i]+tmpmx);
        mxsub = max(mxsub,tmpmx);
    }
    cout << mxsub;
}
