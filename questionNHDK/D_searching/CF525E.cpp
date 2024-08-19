#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
int s;
int a[30],f[30];
unordered_map<int,int>mp[30];
int l = 0,ans = 0;
void dfs1(int x,int sum,int cntk){
    if(cntk > k)return;
    if(sum > s)return;
    if(x == n/2){
        mp[cntk][sum]++;
        return;
    }
    dfs1(x+1,sum,cntk);
    dfs1(x+1,sum+a[x],cntk);
    if(a[x]<=20)dfs1(x+1,sum+f[a[x]],cntk+1);
}

void dfs2(int x,int sum,int cntk){
    if(cntk > k)return;
    if(sum > s)return;
    if(x == n){
        for(int i = 0; i <= k-cntk; i++){
            ans += mp[i][s-sum];
        }
        return;
    }
    dfs2(x+1,sum,cntk);
    dfs2(x+1,sum+a[x],cntk);
    if(a[x] <= 20)dfs2(x+1,sum+f[a[x]],cntk+1);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> k >> s;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    f[1] = 1;
    for(int i = 2; i <= 20; i++){
        f[i] = f[i-1]*i;
    }
    dfs1(0,0,0);
    dfs2(n/2,0,0);
    cout << ans << '\n';
}
