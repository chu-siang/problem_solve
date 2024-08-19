#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 3e4;
int fac[MAXN],inverfac[MAXN];
signed main(){
    int s;
    cin >> s;
    fac[3] = 1,fac[4] = 1,fac[5] = 1;
    for(int i = 6; i <= MAXN; i++){
        fac[i] = (fac[i-1] + fac[i-3])%MOD;
    }
    cout << (fac[s]%MOD);
}