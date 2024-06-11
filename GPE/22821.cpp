#include<bits/stdc++.h>
#define int long long
using namespace std;

char mp[105][105];
bool visit[105][105];
int n,m;
int cnt;
void dfs(int x,int y){
    if(x < 0 || y < 0 || x >= n || y >= m || visit[x][y])return;
    visit[x][y] = 1;
    if(mp[x][y] == '*')return;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int nx = x + i,ny = y + j;
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny] && mp[nx][ny] == '@'){
                dfs(nx,ny);
            }
        }
    }
    return;
}
signed main(){
    while(cin >> n >> m){
        if(n == 0 || m == 0)break;
        memset(visit,0,sizeof(visit));
        cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mp[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visit[i][j] && mp[i][j] == '@'){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}