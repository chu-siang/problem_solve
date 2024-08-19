#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+10;
double a[MAXN],prea[MAXN];
double sl = 1,sr = 1;
int n,d;

bool check(double mid){
    for(int i = 1; i <= n; i++){
        double y = a[i-1] - mid;
        prea[i] = prea[i-1]+y;
    }
    double mi = 0;
    int tl = 1;
    for(int i = d; i <= n; i++){
        if(prea[i-d] < mi){
            mi = prea[i-d];
            tl = i - d + 1;
        }
        if(prea[i] >= mi){
            sr = i;
            sl = tl;
            return 1;
        }
    }
    return 0;
}

signed main(){
    cin >> n >> d;
    for(int i = 0; i < n; i++)cin >> a[i];
    double l = 0, r = 105;
    for(int i = 0; i < 100; i++){
        double mid = (r+l)/2;
        if(check(mid))l = mid;
        else r = mid;
    }
    cout << sl << ' ' << sr;
}