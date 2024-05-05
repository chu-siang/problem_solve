#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int a[MAXN];
int main(){
    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)cin >> a[i];
        sort(a,a+n);
        int ans = 0;
        for(int i = n - 3; i >= 0; i -= 3)ans += a[i];
        cout << ans << '\n';
    }
}