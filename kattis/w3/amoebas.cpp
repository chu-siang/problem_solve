#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[105][105];
int dx[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
bool vis[105][105];

bool ok(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m)return false;
    if(c[x][y] == '.')return false;
    return true;
}

void dfs(int x, int y){
    if(vis[x][y])return;
    vis[x][y] = 1;
    for(int i = 0; i < 8; ++i){
        int nx = x + dx[i][0];
        int ny = y + dx[i][1];
        if(ok(nx,ny)){
            dfs(nx,ny);
        }
    }
}

signed main(){
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <=m; ++j){
            if(c[i][j] == '#' && !vis[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}