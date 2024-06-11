//uva 10057
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN];
signed main(){
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        int cnt = 0;
        int mid1 = a[(n-1)/2];
        int mid2 = a[n/2];
        for(int i = 0; i < n; i++){
            if(mid1 == a[i] || mid2 == a[i])cnt++;
        }
        cout << mid1 << ' ' << cnt << ' ' << mid2-mid1+1 << '\n';
    }
}