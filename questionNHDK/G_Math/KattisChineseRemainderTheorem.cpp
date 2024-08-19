#include<bits/stdc++.h>
#define int long long
using namespace std;

int extgcd(int a,int b,int &x ,int & y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = extgcd(b,a%b,y,x);
    y -= (a/b)*x;
    return d;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        int x,y;
        int m,n;
        cin >> a >> n >> b >> m;
        int g = extgcd(n,-m,x,y);
        if((b-a) % g){
            cout << "no solution" << '\n';
            continue;
        }
        x*=(b-a)/g;
        x = (x%((-m)/g)-m/g)%((-m)/g);
        int MOD = (m)*n/__gcd(m,n);
        cout << ((x*n+a)%MOD+MOD)%MOD << ' ' << MOD << '\n';
    }
}