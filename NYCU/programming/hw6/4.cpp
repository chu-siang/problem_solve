//uva11204
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n,m;//instrument,m:student
        cin >> n >> m;
        ll a[33] = {0};
        ll num;
        ll cnt = 1;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                cin >> num;
                if(num == 1) a[j]++; 
            } 
        for(int i = 0; i < n; i++)if(a[i] > 1)cnt *=a[i];
        cout << cnt << '\n';
    }
}