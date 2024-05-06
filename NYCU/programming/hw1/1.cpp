//a045 重要
#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    ll n,m;
    while(cin >> n >> m){
        if(n > m) swap(n,m);
        cout << min(m - n,100 + n - m) << '\n';
    }

}