#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,t;
    while(cin >> n){
        if(n < 0)break;
        cout << n*(n + 1)/2+1 << '\n';
    }
}