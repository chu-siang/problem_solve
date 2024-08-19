#include<bits/stdc++.h>
#define int long long
using namespace std;

int fastpow(int a,int b,int MOD){
    int res = 1;
    while(b){
        if(b&1LL)res = res * a % MOD;
        a = a*a % MOD;
        b/=2;
    }
    return (res % MOD);
}

signed main(){
    int n;
    cin >> n;
    while(n--){
        int a,b,c;
        cin >> a >> b >> c;
        int MOD = 1e9+7;
        cout << fastpow(a,fastpow(b,c,MOD-1),MOD) << '\n';
    }
}