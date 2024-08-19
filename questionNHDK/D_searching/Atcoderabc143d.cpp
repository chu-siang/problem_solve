#include<bits/stdc++.h>
#define ll long long
using namespace std;

int arr[2005];
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> arr[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < i; j++){
            ans += upper_bound(arr,arr+n,arr[i]+arr[j]-1)-arr-i-1;
        }
    }
    cout << ans << '\n';    
}