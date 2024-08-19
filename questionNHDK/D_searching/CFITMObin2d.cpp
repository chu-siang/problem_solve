#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Assistant{
    int t,z,y,cnt = 0;// a balloon using time t, y: rest time,z = fatigue numbers
}a[1005];
int ans[1005];
int n,m;// n balloons m people
bool check(int time){
    int sum = 0;
    for(int i = 0; i < m; i++){
        ans[i] = time/(a[i].t*a[i].z+a[i].y)*a[i].z;
        ans[i] += min(time % (a[i].t*a[i].z+a[i].y)/a[i].t,a[i].z);
        sum += ans[i]; 
    }
    return sum >= n;
}

signed main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i].t >> a[i].z >> a[i].y;
    }
    int l = 0,r=1;
    while(!check(r)){
        r<<=1;
    }
    if(n == 0){
        r = 0;
    }
    while(r-l > 1){
        int mid = l+r>>1;
        if(check(mid))r=mid;
        else l = mid;
    }
    check(r);
    cout << r << '\n';
    int tot = 0;
    for(int i = 0; i < m; i++){
        tot += ans[i];
        if(tot > n){
            ans[i] -= (tot-n);
            tot = n;
        }
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}