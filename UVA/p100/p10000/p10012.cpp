#include<bits/stdc++.h>
using namespace std;
double r[55],x[55];
void solve(int idx){
    double t;
    x[idx] = r[idx];
    for(int i = 0; i < idx; i++){
        t = sqrt((r[i] + r[idx])*(r[i] + r[idx]) - (r[i] - r[idx])*(r[i] - r[idx])) + x[i];
        x[idx] = max(x[idx],t);
    }
    
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)cin >> r[i];
        sort(r,r+n);
        double ans = 1e50;
        do{
            x[0] = r[0];
            for(int i = 1; i < n; i++)solve(i);
            double tmp = 0;
            for(int i = 0; i < n; i++)tmp = max(tmp,x[i]+r[i]);
            ans = min(ans,tmp);
        }while(next_permutation(r,r+n));
        cout <<fixed << setprecision(3) << ans << '\n';
    }
}