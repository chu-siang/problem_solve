#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5+5;
double a[MAXN];
int n;
double k,eps = 1e-6;

bool check(double mid){
    int cnt = 0;
    vector<double>tmp(a,a+n);
    for(int i = 0; i < n; i++){
        while(tmp[i]-mid > eps){
            cnt++;
            tmp[i]-=mid;
        }
    }
    return cnt >= k;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++) cin>> a[i];
    double l = 0,r = (double)1e13;
    while(r-l>eps){
        double mid = (r+l)/2;
        if(check(mid))l = mid;
        else r = mid;
    }
    cout << setprecision(20)<< l << '\n';
}