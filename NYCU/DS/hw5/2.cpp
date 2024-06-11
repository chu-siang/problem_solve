//uva532
#include<bits/stdc++.h>
using namespace std;

int l,m,n;
char mp[30][30][30];
bool vis[30][30][30];
int dr[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,-1,0},{0,1,0}};
struct Pt{
    int x,y,z;
    int t;
};
Pt S;
int bfs(){
    memset(vis,0,sizeof(vis));
    queue<Pt>q;
    q.push(S);
    while(q.size()){
        Pt now = q.front();
        q.pop();
        vis[now.x][now.y][now.z] = 1;
        if(mp[now.x][now.y][now.z] == 'E'){
            return now.t;
        }
        
        for(int i = 0; i < 6; i++){
            int nx = now.x+dr[i][0],ny = now.y+dr[i][1],nz = now.z+dr[i][2];
            if(nx >= 0 && nx < l && ny >= 0 && ny < m && nz >= 0 && nz < n){              
                if(!vis[nx][ny][nz] && mp[nx][ny][nz]!='#'){             
                    q.push({nx,ny,nz,now.t+1});
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> l >> m >> n;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                cin >> mp[i][j][k];
                if(mp[i][j][k] == 'S'){
                    S = {i,j,k,0};
                }
            }
        }
    }
    int ans = bfs();
    if(ans == -1){
        cout << "Trapped!\n";
    }else cout << "Escaped in " << ans << " minute(s).\n";
}
