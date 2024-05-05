#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll f(int t){
    if(t >= 101)return t-10;
    return f(f(t+11));
}

int main(){
    ll t;
    while(cin >> t,t){
        cout << "f91(" << t << ") = " << f(t) << '\n';
    }
}