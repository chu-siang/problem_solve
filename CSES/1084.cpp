#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =2e5+5;
int a[MAXN],b[MAXN];
signed main(){
    int n,k,m;
    cin >> n >> m >> k;
    int cnt = 0;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < m; i++)cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    int l = 0, h = 0;
    while(l < n &&  h < m){
        if(abs(a[l] - b[h]) <= k){
            l++;
            h++;
            cnt++;
        }else{
            if(a[l] < b[h])l++;
            else h++;
        }
    }
    cout << cnt ;
}