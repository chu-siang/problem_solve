//opening ceremony
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int a[MAXN];
signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int mn = 0;
    for(int i = 0; i < n; i++){
        mn = min(mn+1, a[i]);
    }
    cout << mn;

}