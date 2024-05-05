#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n,m;
    while(cin >> n >> m){
        if(n == m && n == 0) break;
        ll carry = 0;
        if(n > m) swap(n,m);
        int car = 0;
        while(m > 0){
            int a = n % 10;
            int b = m % 10;
            m /= 10;
            n /= 10;
            if(a + b + car >= 10){
                carry++;
                car = 1;
            }else {
                car = 0;
            }
        }
        if(carry == 0) cout << "No carry operation.\n";
        else if(carry == 1) cout << carry << " carry operation.\n";
        else cout << carry << " carry operations.\n";
    }
}