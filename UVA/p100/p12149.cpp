#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t;
    ll a[106];
    a[0] = 0;
    for(int i = 1; i <= 105; i++){
        a[i] = a[i-1] + i*i;
    }
    while(cin >> t,t){
        cout << a[t] << '\n';
    }
}