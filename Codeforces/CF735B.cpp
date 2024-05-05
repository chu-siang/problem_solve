#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(ll i = 0; i < n; i++) cin >> arr[i];

        ll ans = -1e18;
        for(ll i = max(0LL, n - 2 * k - 1); i < n; i++){
            for(ll j = i + 1; j < n; j++){
                ans = max(ans, (i+1) * (j+1) - k * (arr[i] | arr[j]));
            }
        }
        cout << ans << '\n';
    }
    
}