#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e6+5;
int fac[MAXN],inverfac[MAXN];
double fastpow(double a,int b){
    double res = 1;
    while(b){
        if(b&1)res = a * res;
        a *= a;
        b>>=1;
    }
    return res;
}


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    double m;
    int n;
    cin >> m >> n;
    double s = 0;
    for(double i = 1; i <= m; i++){
        s+= (fastpow(i/m,n) - fastpow((i-1)/m,n))*i;
    }
    cout << s << '\n';
}