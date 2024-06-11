#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,l,u,ans;
    while(cin >> n >> l >> u){
        ans = 0;
        for(int i = 31; i >= 0; i--){
            if((ans|(1LL<<i)) > u)continue;
            if((ans|(1LL<<i)) <= l || !(n&(1LL << i))){
                ans|=(1LL<<i);
            }
        }
        cout << ans << '\n';
    }
}