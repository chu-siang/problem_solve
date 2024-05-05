//uva913
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    while(cin >> n){
        ll t = (n + 1)*(n + 1)/4;
        cout << (6*t - 9) << '\n';
    }
}
