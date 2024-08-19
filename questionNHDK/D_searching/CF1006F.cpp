#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k;
ll middle;
ll a[25][25];
ll ans = 0;
ll n,m;
map<ll,int>mp[20][20];
void sub(int x,int y,ll val,int cnt){
    val^=a[x][y];
    if(cnt == middle){
        ++mp[x][y][val];
        return;
    }
    if(x + 1 < n){
        sub(x+1,y,val,cnt+1);
    }
    if(y + 1 < m){
        sub(x,y+1,val,cnt+1);
    }
}

void sub2(int x,int y,ll val,int cnt){
    if(cnt == n+m-2-middle){
        if(mp[x][y].count(k ^ val))ans+=mp[x][y][k^val];
        return;
    }
    if(x > 0){
        sub2(x-1,y,val^a[x][y],cnt+1);
    }
    if(y > 0){
        sub2(x, y - 1, val^a[x][y], cnt+1);
    }
}

int main(){
    cin >> n >> m;
    cin >> k;
    middle = (n+m-2)/2;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    sub(0,0,0,0);
    sub2(n-1,m-1,0,0);
    cout << ans << '\n';
}