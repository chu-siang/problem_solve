#include<bits/stdc++.h>
using namespace std;
string a,b,ans;

int idx = 0;
void dfs(int l,int r){
    if(l > r)return;
    int i = l;
    for(;i <= r; i++){
        if(a[idx] == b[i])break;
    }
    if(i != r+1){
        idx++;
        dfs(l,i-1);
        dfs(i+1,r);
        ans += b[i];
    }
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char c;
        ans = "",a = "",b = "";
        for(int i = 0; i < n; i++){
            cin >> c;
            a += c;
        }
        for(int i = 0; i < n; i++){
            cin >> c;
            b += c;
        }
        idx = 0;
        dfs(0,n-1);
        for(int i = 0; i < n; i++){
            cout << ans[i] << " \n"[i==n-1];
        }
    }
}