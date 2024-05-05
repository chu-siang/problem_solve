#include<bits/stdc++.h>
using namespace std;
int a[45];
long long n,x;
unordered_map<int,int>mp;
void dfs1(int now,long long val){
    if(val > x)return;
    if(now == (n>>1)){
        mp[val]++;
        return;
    }
    dfs1(now+1,val+a[now]);
    dfs1(now+1,val);
}
long long ans;
void dfs2(int now,long long val){
    if(val > x)return;
    if(now == n){
        ans+=mp[x-val];
        return;
    }
    dfs2(now+1,val+a[now]);
    dfs2(now+1,val);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a,a+n,cmp);
    dfs1(0,0);
    dfs2((n>>1),0);
    cout << ans;
    return 0;
}