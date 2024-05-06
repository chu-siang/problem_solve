//uva12650
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,r;
    while(cin >> n >> r){
        bool a[1005];
        memset(a,0,sizeof(a));
        int re;
        for(int i = 0 ;i < r; i++){
            cin >> re;
            a[re]++;
        }
        bool flag = false;
        for(int i = 1; i <= n; i++){
            if(!a[i]){
                flag = true;
                cout << i << ' ';
            }
        }
        if(!flag)cout <<'*';
        cout << '\n';
    }
}