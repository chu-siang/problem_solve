#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n,m;
    ll t;
    ll p,h;
    cin >> t;
    while(t--){
        cin >> n >> p;
        ll arr[n+1];
        memset(arr,0,sizeof(arr));
        ll sum = 0;
        for(int i = 0; i < p; i++){
            cin >> h;
            for(int j = h; j <= n; j+= h){
                arr[j] = 1;
            }
        }
        for(int i = 7; i <= n; i+=7){
            arr[i] = 0;
        }
        for(int i = 6; i <= n; i+=7){
            arr[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            sum += arr[i];
        }
        cout << sum << '\n';
    }
}