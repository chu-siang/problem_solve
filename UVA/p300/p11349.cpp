#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 105;
ll a[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    for(int c = 1; c <= t; c++){
        ll n;
        char ch;
        cin >> ch >> ch >> n;
        memset(a,-1,sizeof(a));
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
                if(a[i][j] < 0) flag = true;
            }
        }
        for(ll i = 0; i <= n/2; i++){
            for(ll j = 0; j < n; j++){
                if(a[n-1-i][n-1-j] !=a[i][j]){
                    flag = true;
                    break;
                }
            }
        }
        cout << "Test #" << c << ": ";
        if(!flag)cout << "Symmetric.\n";
        else cout << "Non-symmetric.\n";
    }
    return 0;
}