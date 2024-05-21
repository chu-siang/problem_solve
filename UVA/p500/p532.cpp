#include<bits/stdc++.h>
using namespace std;
int l,r,c;
char mp[31][31][31];
bool visit[31][31][31];
int dx[6][3] = {{0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,1},{0,0,-1}};
struct Pt{
    int x,y,z;
    int cnt;
};
signed main(){
    while(cin >> l >> r >> c){
        if(l == r && r == c&&c == 0)break;
        queue<Pt>q;
        memset(visit,0,sizeof(visit));
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> mp[i][j][k];
                    if(mp[i][j][k]=='S')q.push({i,j,k,0});
                }
            }
        }
        int ans = -1;
        while(q.size()){
            Pt now = q.front();
            q.pop();
            visit[now.x][now.y][now.z] = 1;
            if(mp[now.x][now.y][now.z] == 'E'){
                ans = now.cnt;
                break;
            }
            for(int i = 0; i < 6; i++){
                int nx = now.x+dx[i][0],
                    ny = now.y+dx[i][1],
                    nz = now.z+dx[i][2];
                if(!visit[nx][ny][nz] && mp[nx][ny][nz] != '#'&& nx >= 0 &&
                    nx < l && ny >= 0 && ny < r && nz >= 0 && nz < c){
                        q.push({nx,ny,nz,now.cnt+1});
                        visit[nx][ny][nz] =1;
                }
            }
        }
        if(ans!=-1) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
    }

}