#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,k;
const int MAXN = 1e5+5;
int arr[MAXN] = {0};

bool ok(ll sum){
    int count = 0;
    ll tmp = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > sum) return false;
        if(tmp + arr[i] > sum){
            tmp = 0;
            count++;
        }
        tmp += arr[i];
    }
    if(tmp) count++;
    return (count<=k);
}

int main(){
    cin >> n >> k; 
    ll l = 0, r = 0,mid;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        r += arr[i];
    }
    ll ans = 0;
    while(l <= r){
        mid = (l + r)/2;
        if(ok(mid)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
