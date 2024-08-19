#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
const int MAXN = 1e5+5;
int fac[MAXN],inverfac[MAXN];

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1)res = a * res % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    fac[0] = inverfac[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fac[i] = i * fac[i-1] % MOD;
    }
    for(int i = 1; i <= MAXN; i++){
        inverfac[i] = fastpow(fac[i],MOD - 2)% MOD;
    }
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
            string s;
        cin >> s;
        int n = 0, m = 0;
        int l = s.length();
        for(int i = 0; i < l; i++){
            if(s[i] == '0')n++;
            else if(s[i] == '1'){
                if(i + 1 < l && s[i + 1] == '1'){
                    n++,m++,i++;
                }
            }
        }
        cout << (fac[n]*inverfac[m]%MOD*inverfac[n-m]% MOD + MOD) %MOD << '\n';
    }
}
