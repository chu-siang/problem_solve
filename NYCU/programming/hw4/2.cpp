//11461
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a,b;
    while(cin >> a >> b,a){
        if(a > b)swap(a,b);
        ll s1 = sqrt(b);
        ll s2 = sqrt(a);
        if(s2*s2 != a) s2++;
        cout << s1 - s2 + 1 << '\n';
    }
}