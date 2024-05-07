#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mypow(ll x,ll y){
    ll ans = 1;
    while(y){
        if(y & 1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}


int main(){
    int t;
    string s;
    while(cin >> t){
        cin.ignore();
        getline(cin,s);
        stringstream ss(s);
        ll num;
        ll ans = 0;
        ll n = 0;//算n有幾項
        stack<ll>stk;
        while(ss >> num){
            stk.push(num);
            n++;
        }
        n--;
        stk.pop();
        for(int i = 0; i < n; i++){
            ll c = stk.top();
            stk.pop();
            ans += (c*(i+1)*mypow(t,i));
        }
        cout << ans << '\n';
        while (!stk.empty()){
            stk.pop();
        }
        
    }
    return 0;
}

