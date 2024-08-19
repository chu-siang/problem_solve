#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    double l =0, r = 1e18;
    for(int i = 0; i < 100; i++){
        double mid = (l + r)/2;
        ll total = 0;
        for(int j = 0; j < n; j++){
            total += (ll)(a[j]/mid);
            if(total >= k)break;
        }
        if(total >= k) l = mid;
        else r = mid;
    }
    cout << setprecision(10) << l << endl;
}