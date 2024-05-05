#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n, m;
    while(cin >> n >> m){
        ll count = 1;
        vector<ll>v;
        if((m == 1)|| (n == 0) || (m==0) || n == 1){
            cout << "Boring!\n";
            continue;
        }
        v.emplace_back(n);
        bool flag = false;
        while(n){
            if(n == 1){
                flag = true;
                v.emplace_back(n);
                break;
            }
            if(n % m == 0){
                count++;
                n/=m;
                v.emplace_back(n);
            }else {
                break;
            }
        }
        if(!flag) cout << "Boring!\n";
        else {
            for(ll i = 0; i < count; i++ ){
                cout << v[i] << " \n"[i==count-1];
            }
        }
    }
}
