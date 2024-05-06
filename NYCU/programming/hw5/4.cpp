//10696
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll n){
    if(n >= 101) return n-10;
    return f(f(n+11));
}

int main(){
    ll n;
    while(cin >> n,n){
        cout << "f91("<<n<<") = " << f(n) << '\n';
    }
}
/*A 183-5724 17 58 18 04*/