#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n),d(n);
        for(auto &i : v)cin >> i;
        if(n == 1){
            cout << 1 << '\n';
            continue;
        }
        for(int i = 0; i < n - 1; i++)d[i] = abs(v[i+1]-v[i]);
        int mx = 0;
        for(int i = 0; i < n - 1; i++){
            int gcd = d[i], len = 1;
            for(int j = i; j < n - 1; j++){
                gcd = __gcd(d[j],gcd);
                d[j]/=gcd;
                if(gcd == 1)break;
                len++;
            }
            mx = max(len,mx);
        }
        cout << mx << '\n';
    }

}
