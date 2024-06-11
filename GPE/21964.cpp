#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1005];

bool f(int mid){
    int sum = 0,cnt = 1;
    for(int i = 0; i < n; i++){
        if(sum + a[i] > mid){
            if(a[i] > mid){
                return 0;
            }
            sum = a[i],cnt++;
        }else{
            sum += a[i];
        }
    }
    return cnt <= m;
}

signed main(){
    while(cin >> n >> m){
        for(int i = 0; i < n; i++)cin >> a[i];
        int l = 0, r = 1e10;
        while(r-l > 1){
            int mid = l+r>>1;
            if(f(mid)) r = mid;
            else l = mid;
        }
        cout << r << '\n';
    }
}