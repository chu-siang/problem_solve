#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int>v;
int ans = 0;


void dfs(int l,int r){
    if(l == r) return;
    int mid = l+r>>1;
    dfs(l,mid);
    dfs(mid+1,r);

    vector<int>sorted;
    int lptr = l,rptr = mid+1;
    int cnt = 0;
    while(lptr <= mid && rptr <= r){
        if(v[lptr] > v[rptr]){
            sorted.push_back(v[lptr++]);
            cnt++;
        }else{
            sorted.push_back(v[rptr++]);
            ans += cnt;
        }
    }

    while(lptr <= mid){
        sorted.push_back(v[lptr++]);
        cnt++;
    }
    while(rptr <= r){
        sorted.push_back(v[rptr++]);
        ans += cnt;
    }
    int p = l;
    for(auto k : sorted)v[p++] = k;
}


signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    int n;
    int C = 0;
    while(cin >> n,n){
        v.clear();
        v.resize(n);
        ans = 0;
        for(int i = 0; i < n; i++)cin >> v[i];
        dfs(0,n-1);
        cout <<"Case #" << ++C << ": " << ans << '\n';
    }
}