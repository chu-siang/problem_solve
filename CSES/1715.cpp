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
        if(b&1)res = res * a% MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    fac[0] = 1;
    inverfac[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fac[i] = fac[i-1]*i%MOD;
        inverfac[i] = fastpow(fac[i],MOD-2);
    }
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        arr[(int)(s[i]-'a')]++;
    }
    int l = s.length();
    int sum = fac[l];
    for(int i = 0; i < 26; i++){
        sum = sum * inverfac[arr[i]] %MOD;
    }
    cout << sum << '\n';
}