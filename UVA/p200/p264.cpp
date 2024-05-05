#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    while(cin >> n){
        ll k = n;
        for(int i = 1; i <= n ;i++){
            if(k <= i){
                if(i&1) cout << "TERM "<< n << " IS " << (i+1-k) << "/"<< k <<'\n';
                else cout << "TERM "<< n << " IS " << k << "/"<<(i+1-k)<<'\n';
                break;
            }else k-=i;
        }
    }
}