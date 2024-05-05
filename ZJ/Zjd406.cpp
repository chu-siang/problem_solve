#include<bits/stdc++.h>
using namespace std;

int mp[105][105] = {0};
int move_x[4] = {1,-1,0,0};
int move_y[4] = {0,0,1,-1};
bool visited[105][105] = {0};
queue<pair<int,int>>q;

void bfs(int s){

    while(q.size()!= 0 && s == 1){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(mp[x+move_y[i]][y+move_x[i]] == 1 && visited[x+move_y[i]][y+move_x[i]] == 0){
                q.emplace(make_pair(x+move_y[i],y+move_x[i]));
                mp[x+move_y[i]][y+move_x[i]] = mp[x][y]+1;
                visited[x+move_y[i]][y+move_x[i]] = 1;
            }
        }
    }
    while(q.size() != 0 && s == 2){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 3; i++){
            if(mp[x+move_y[i]][y+move_x[i]] == 1 && visited[x+move_y[i]][y+move_x[i]] == 0){
                q.emplace(make_pair(x+move_y[i],y+move_x[i]));
                mp[x+move_y[i]][y+move_x[i]] = mp[x][y]+1;
                visited[x+move_y[i]][y+move_x[i]] = 1;
            }
        }
    }
}

int main(){
    int n,m;
    int s;
    int t = 1;
    while(cin >>s){
        cin >> n >> m;
        memset(visited,0,sizeof(visited));
        memset(mp,0,sizeof(mp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mp[i][j];
                if(i == 0 && mp[i][j] == 1){
                    q.emplace(make_pair(i,j));
                    visited[i][j] = 1;
                }
            }
        }
        cout << "Case "<< t++ << ":" << '\n';
        bfs(s);
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mp[i][j] == 1) mp[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << mp[i][j] << " \n"[j==m-1];
            }
        }
    }
}