#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    double cha = 0;
    while(n--){
        double x;
        int ans;
        cin >> x;
        if(cha < 0) ans = ceil(x);
        else ans = floor(x);
        cout << ans << '\n';
        cha += ans-x;
    }
}