#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ans[88] = {0};
ll f(int n){
    if(n == 1)return 1;
    return f(n-1)+f(n-2);
}

int main(){
    ll t;
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ans[1] = 1,ans[2] = 2;
    for(int i = 3; i <= 88; i++){
        ans[i] = ans[i-1]+ans[i-2];
    }
    while(cin >> t,t){
        cout << ans[t] << '\n';
    }
}