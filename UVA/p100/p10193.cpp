#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll StoN(string s){
    ll ans = 0;
    for(int i = 0;i < s.size();i++){
        ans *= 2;
        ans += (s[i] - '0');
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    string s1,s2;
    for(ll i = 1; i <= n; i++){
        cin >> s1 >> s2;;
        ll a = StoN(s1),b = StoN(s2);
        cout << "Pair #" << i << ": ";
        if(a < b)swap(a,b);
        if (__gcd(a,b) > 1)cout << "All you need is love!\n";
        else cout << "Love is not all you need!\n";
    }
}
