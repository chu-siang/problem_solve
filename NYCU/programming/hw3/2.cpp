//uva 12149
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    while(cin >> n,n){
        ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum +=(i*i);
    }
        cout << sum << '\n';
    }
    return 0;
}