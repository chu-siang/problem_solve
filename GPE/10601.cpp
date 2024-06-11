#include<bits/stdc++.h>
#define int long long
using namespace std;
int row,column;
bool visit[305][305][3];
char mp[305][305];
int dr[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int ans;
struct node{
    int x, y,cnt;
};

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> row >> column;
        int x,y;
        ans = 1e12;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column;  j++){
                cin >> mp[i][j];
                if(mp[i][j] == 'S')x=i,y=j;
            }
        }
        queue<node>q;
        q.push({x,y,0});
        memset(visit,0,sizeof(visit));
        while(q.size()){
            node now = q.front();
            q.pop();
            if(mp[now.x][now.y] == 'E'){
                ans = min(ans,now.cnt);
                break;
            }
            for(int i = 0; i < 4; i++){
                int nx = now.x,ny = now.y;
                int time = now.cnt%3+1;
                bool flag = false;
                for(int j = 0; j < time; j++){
                    nx += dr[i][0];
                    ny += dr[i][1];
                    if(nx < 0 || ny < 0 || nx >= row || ny >= column || mp[nx][ny] == '#'){
                        flag = true;
                        break;
                    }
                }
                if(flag)continue;
                if(mp[nx][ny] != '#' && !visit[nx][ny][(now.cnt+1)%3]){
                    q.push({nx,ny,now.cnt+1});
                    visit[nx][ny][(now.cnt+1)%3] = 1;
                }
            }
        }
        if(ans !=1e12)cout << ans << '\n';
        else cout << "NO\n";
    }
}