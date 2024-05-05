#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    vector<ll>fib;
    ll f0 = 0, f1 = 1, f2 = 1;
    for(;f2 <= 1e8;){
        f2 = f1 + f0;
        fib.push_back(f2);
        f0 = f1;
        f1 = f2;
    }
    reverse(fib.begin(),fib.end());
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll k = n;
        ll i = 0;
        vector<int>ans;
        while(fib[i] > n)i++;
        for(; i < fib.size(); i++){
            if(n >= fib[i]){
                n-=fib[i];
                ans.push_back(1);
                i++;
               if(i < fib.size())ans.push_back(0);
            }else ans.push_back(0);
        }
        cout << k << " = ";
        for (auto j: ans) cout << j;        
        cout << " (fib)\n";
    }
    
}