//12459
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[90] = {0};

ll f(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(a[n])return a[n];
    return a[n] = f(n-2) + f(n-1);
}


int main(){
    ll n;
    while(cin >>n,n){
        cout << f(n) << '\n';
    }
}
/*A 183-5724 17 58 18 04*/