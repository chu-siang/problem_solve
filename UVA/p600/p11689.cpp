#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin >> n;
    ll e,f,c;
    while(n--){
        //empty battle(possession)    found during  require to buy new
        cin >> e >> f >> c;
        ll ans = 0;
        e+=f;
        while(e >= c){
            ans += (e/c);
            e = (e/c) + (e%c);
        }
        cout <<ans << '\n';
    }
}