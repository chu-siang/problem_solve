#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 505;
ll ans[MAXN] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n;
    while(cin >> n,n){
        ll g = 0;
        for(int i = 1; i < n; i++){
            
            for(int j = i+1; j <= n; j++){
                g+=__gcd(i,j);
            }
        }
        cout << g << '\n';
    }
    return 0;
}