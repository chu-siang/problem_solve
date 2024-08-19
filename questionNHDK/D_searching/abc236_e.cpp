#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+10;
int n;
double a[MAXN],b[MAXN],dp[MAXN];
int R,L = 0;
double l,r;
double eps = 1e-5;

bool check(double mid){
    for(int i = 1; i <= n; i++) b[i] = a[i] - mid;
    dp[1] = b[1];
    for(int i = 2; i <= n; i++) dp[i] = max(dp[i-1],dp[i-2])+b[i];
    if(dp[n] >= 0||dp[n-1] >= 0)return true;
    else return false;
}

bool check2(int mid){
    for(int i = 1; i <= n; i++){
        if(a[i] >= mid) b[i] = 1;
        else b[i] = -1;
    }
    dp[1] = b[1];
    for(int i = 2; i <= n; i++) dp[i] = max(dp[i-1],dp[i-2])+b[i];
    if(dp[n] > 0||dp[n-1] > 0)return true;
    else return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] > r) r = a[i];
    }
    R = r+1;
    while(r-l > eps){
        double mid = (r+l)/2;
        if(check(mid))l = mid;
        else r = mid;
    }
    cout << l << '\n';
    while(R-L>1){
        int mid = (R+L)>>1;
        if(check2(mid))L = mid;
        else R = mid;
    }
    cout << L;
}
