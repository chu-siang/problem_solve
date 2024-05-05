//uva11059
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    ll c = 0;
    while(cin >> n){
        ll a[20];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ll mx = -1e9;
        for(int i = 0; i < n; i++){
            ll tmp = 1;
            for(int j = i; j < n; j++){
                tmp *= a[j];
                if(mx < tmp) mx = tmp;
            }
        }
        if(mx < 0) mx = 0;
        cout << "Case #" << ++c <<": " <<"The maximum product is " << mx << ".\n\n";
    }
}