#include<iostream>
#include<cmath>
#include<bitset>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x;
    int n;
    cin >> n;
    while(n--){
        cin >> x;
        bool flag = true;
        for(ll a = 1; a * a * a <= x; a++){
            ll b = x - a * a * a;
            ll u = cbrt(b);
			if(u == 0) continue;
            if(u * u * u == b){
                cout << "YES" << '\n';
                flag = false;
                break;
            }
        }
        if(flag) cout << "NO" << '\n';
    }
    return 0;
}