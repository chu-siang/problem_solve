#include<bits/stdc++.h>
#define int long long
using namespace std;
int b,p,m;
int fastpow(int a,int r){
    int ans = 1;
    if(r == 0)return 1;
    if(r == 1)return a;
    if(r&1)ans = a%m;
    int tmp = fastpow(a,r/2)%m;
    ans = ((ans*tmp)%m)*tmp%m;
    return (ans%m);
}
signed main(){
    while(cin >> b >> p >> m){
        cout << fastpow(b,p)%m << '\n';
    }
}