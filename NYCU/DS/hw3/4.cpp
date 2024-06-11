#include<bits/stdc++.h>
using namespace std;
int n,m;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int a[305][305];
void dfs(int x,int y){
    if(x < 0 || y < 0 || x >= n || y >= m)return;
    if(a[x][y] == 0)return ;
    a[x][y] = 0;
    for(int i = 0; i < 4; i++){
        dfs(x+dx[i],y+dy[i]);
    }
    return;
}
signed main(){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout << ans << '\n';
}