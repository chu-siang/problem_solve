#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
int a[MAXN];

int extgcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }else{
        int d = extgcd(b,a%b,y,x);
        y = y-a/b*x;
        return d;
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    int n,s,k;
    while(t--){
        cin >> n >> s >> k;
        int x,y;
        int g = extgcd(k,n,x,y);
        cout << "g: " << g << ", x : " << x << ", y : " << y << '\n';
        if(s%g){
            cout << "-1" << '\n';
            continue;
        }
        s/=g;
        n/=g;
        x*=(-s);
        cout << (x%n+n)%n << '\n';
    }
    return 0;
}   