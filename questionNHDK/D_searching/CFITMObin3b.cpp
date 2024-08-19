#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+10;
int a[MAXN];
int n,k;
bool check(int mid){
    int cnt = 0;
    int x = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > mid)return false;
        if(x + a[i] <= mid){
            x+=a[i];
        }else{
            x = a[i];
            cnt++;
        }
        if(cnt > k)break;
    }
    if(x)cnt++;
    return cnt <= k;
}


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    int l = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int r = 1e18;
    while(r - l > 1){
        int mid = r+l>>1;
        if(check(mid))r = mid;
        else l = mid;
    }
    cout << r << '\n';
}