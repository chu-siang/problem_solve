#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    int mn = 1e9;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    bool flag = false;
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] < a[i-1]){
            if(i == n)a[i] = 1e5+5;
            else if(a[i]  < a[i-2])a[i] = a[i-1];
            else a[i-1] = a[i-2];
            cnt++;
        }
    }
    for(int i = 2; i <= n; i++){
        if(a[i] < a[i-1])flag = true;
    }
    if(cnt >= 2 || flag)cout << "NO\n";
    else cout << "YES\n";
}