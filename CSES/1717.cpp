#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e6+5;
int fac[MAXN],inverfac[MAXN];
int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return (res % MOD);
}


signed main(){
    fac[0] = inverfac[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fac[i] = fac[i-1]*i%MOD;
    }
    for(int i = 1; i < MAXN; i++){
        inverfac[i] = fastpow(fac[i],MOD-2);
    }
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(i&1) ans += fac[n-i]*(-1)*fac[n]%MOD*inverfac[i]%MOD*inverfac[n-i]%MOD;
        else ans += fac[n-i]*fac[n]%MOD*inverfac[i]%MOD*inverfac[n-i]%MOD;
        ans %= MOD;
    }
    cout << (ans%MOD+MOD)%MOD << '\n';
}