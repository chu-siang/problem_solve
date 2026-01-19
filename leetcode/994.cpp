class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>grid_vis(n,vector<bool>(m,false));
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 2)q.push({i,j});
                if(grid[i][j] == 1)cnt++,grid_vis[i][j] = true;
            }
        }
        if(cnt == 0)return 0;
        if(q.empty())return -1;
        int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        int minute = -1;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                pair<int,int>tmp;
                tmp = q.front();
                q.pop();
                grid_vis[tmp.first][tmp.second] = false;
                for(int i = 0; i < 4; ++i){
                    int nx = tmp.first + dir[i][0];
                    int ny = tmp.second + dir[i][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && 
                    grid_vis[nx][ny]){
                        grid_vis[nx][ny] = false;
                        q.push({nx,ny});
                        cnt--;
                    }
                }
            }
            minute++;
        }
        if(cnt == 0)return minute;
        return -1;
    }
};