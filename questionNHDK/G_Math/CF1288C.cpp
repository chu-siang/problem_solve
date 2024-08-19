#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 2e4;
int fac[MAXN],inverfac[MAXN];


int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1)res = res*a%MOD;
        a = a * a % MOD;
        b>>=1;
    }
    return (res % MOD);
}

signed main(){
    int n,m;
    cin >> n >> m;
    inverfac[0] = fac[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fac[i] = fac[i-1]*i%MOD;
    }
    for(int i = 1; i <= MAXN; i++){
        inverfac[i] = fastpow(fac[i],MOD-2);
    }
    m = 2*m;
    cout << ((fac[n+m-1]*inverfac[m]%MOD*inverfac[n-1])%MOD + MOD)%MOD << '\n';
}