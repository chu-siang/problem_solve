#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1)res = res*a % MOD;
        a = a * a % MOD;
        b/=2;
    }
    return res;
}


signed main(){
    int n;
    cin >> n;
    int a,b;
    while(n--){
        cin >> a >> b;
        cout << fastpow(a,b) << '\n';
    }
}