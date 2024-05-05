#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
ll n,k;
bool check(ll mid){
    ll cnt = 1;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + a[i] > mid){
            cnt++;
            sum = a[i];
            if(sum > mid)cnt = k+1;
        }else sum += a[i];
    }
    return cnt <= k;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll l = 0,r = 1e14;
    while(r-l > 1){
        ll mid = l+r>>1;
        if(check(mid)) r = mid;
        else l = mid;
    } 
    cout << r << '\n';
}