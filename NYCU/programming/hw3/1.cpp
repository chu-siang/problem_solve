//uva 11764
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// 找中位數
int main(){
    ll t;
    cin >> t;
    for(int Case = 1; Case <= t;Case++){
        int n;
        cin >> n;
        ll a[55];
        ll h = 0, l = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 1; i < n; i++){
            if(a[i] - a[i-1] > 0)h++;
            else if(a[i] - a[i-1] < 0)l++;
        }
        cout << "Case " << Case <<": " << h << " " << l;
        cout << '\n';
    }
}