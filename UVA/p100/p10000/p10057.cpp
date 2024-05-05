#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e6+5;
ll arr[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    double p;
    ll n,k;
    ll s;
    
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        int mid1 = arr[(n-1)/2];
        int mid2 = arr[n/2];
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == mid1 || arr[i] == mid2){
                ans++;
            }
        }
        cout << mid1 << ' ' << ans << ' ' << mid2-mid1+1 << '\n';
    }
}