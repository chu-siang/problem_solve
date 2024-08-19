#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
int a[MAXN];


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int g = a[0];
    for(int i = 1; i < n; i++){
        g = __gcd(a[i],g);
    }
    int q;
    cin >> q;
    int x;
    while(q--){
        cin >> x;
        x-=1115;
        if(x % g == 0)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}   