#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,t;
int a[45];
vector<int>v,v2;

void dfs1(int x,int val){
    if(val > t)return;
    if(x == n/2){
        v.push_back(val);
        return;
    }
    dfs1(x+1,val);
    dfs1(x+1,val+a[x]);
}
void dfs2(int x,int val){
    if(val > t)return;
    if(x == n){
        v2.push_back(val);
        return;
    }
    dfs2(x+1,val);
    dfs2(x+1,val+a[x]);
}

signed main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dfs1(0,0);
    dfs2(n/2,0);
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    int ans = 0;
    for(auto i : v){
        int pos = upper_bound(v2.begin(),v2.end(),t-i)-v2.begin()-1;
        if(pos>=0)ans = max(ans,i+v2[pos]);
        else ans = max(ans,i);
    }
    cout << ans << '\n';
}