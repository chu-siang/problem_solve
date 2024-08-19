#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6+5;
const int MOD = 1e9+7;
int arr[27] = {0};
int fac[MAXN],inverfac[MAXN];

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a * a%MOD;
        b >>= 1;
    }
    return (res%MOD);
}


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int ans = fastpow(10,n)%MOD;
    ans -= (2*fastpow(9,n)%MOD);
    ans += (fastpow(8,n) % MOD);
    cout << (ans%MOD+MOD)%MOD << '\n';
}