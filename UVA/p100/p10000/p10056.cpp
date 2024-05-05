#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    double p;
    ll n,k;
    ll s;
    cin >> s;
    while(s--){
        cin >> n >> p >> k;
        if(p == 0){
            cout << "0.0000\n";
            continue;
        }
        double a = pow(1-p,k-1)*p;
        double b = 1-pow(1-p,n);
        cout << fixed << setprecision(4) << (a/b) << '\n';

    }
}