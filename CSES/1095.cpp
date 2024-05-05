#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;

int fastpow(int a, int b){
    if(b == 0)return 1;
    if(b == 1)return a;

    int mid = fastpow(a,b/2);
    if(b&1)return mid * mid % MOD * a % MOD;
    else return mid * mid % MOD;
}

signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;
    int a,b;
    while(n--){
        cin >> a >> b;
        cout << fastpow(a,b) << '\n';
    }
}