#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 20005;


ll g(ll n){
    if(n < 10) return n;
    ll tmp = 0;
    while(n){
        tmp+=(n%10);
        n/=10;
    }
    return g(tmp);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n;
    while(cin >> n,n){
        cout << g(n) << '\n';
    }
    return 0;
}