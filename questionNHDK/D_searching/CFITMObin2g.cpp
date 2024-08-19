#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,n;
int a[100];

bool check(int mid){
    int tot = k*mid;
    for(int i = 0; i < n; i++){
        tot -= min(a[i],mid);
    }
    return tot > 0;
}

signed main(){
    cin >> k >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    int l = 0,r = 1;
    while(!check(r)){
        r <<= 1;
    }
    while(r - l > 1){
        int mid = l+r>>1;
        if(check(mid))r = mid;
        else l = mid;
    }
    cout << l << '\n';
}