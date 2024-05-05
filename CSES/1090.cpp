#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =2e5+5;
int a[MAXN];

signed main(){
    int n,x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    int ans = 0;
    for(int i = n-1, j = 0; i >= j;){
        if(a[i] + a[j] <= x){
            j++;
            i--;
        }else{
            i--;
        }
        ans++;
    }
    cout << ans << '\n';
}