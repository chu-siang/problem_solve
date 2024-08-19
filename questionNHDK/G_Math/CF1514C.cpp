#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int mul = 1,cnt = 0;
    for(int i = 1; i <= n; i++){
        if(__gcd(n,i) == 1)mul = mul * i % n, cnt++;
    }
    cout << cnt - (mul > 1) << '\n';
    for(int i = 1; i <= n; i++){
        if(i == mul && mul > 1)continue;
        if(__gcd(i,n) == 1)cout << i << ' ';
    }
}
