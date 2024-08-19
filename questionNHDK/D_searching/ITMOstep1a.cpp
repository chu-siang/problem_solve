#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll num;
    sort(v.begin(),v.end());
    while(q--){
        cin >> num;
        int l = 0, r = n - 1;
        while(l < r){
            ll mid = (l+r)/2;
            if(v[mid] > num){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << ((v[l] == num)?"YES" : "NO");
    }
    return 0;
}