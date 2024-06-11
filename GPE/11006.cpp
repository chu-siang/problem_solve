#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
bool visit[1005][1005];
int dr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
void dfs(int x,int y,char c){
    if(visit[x][y])return;
    visit[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dr[i][0], ny = y + dr[i][1];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m &&mp[nx][ny] == c && !visit[nx][ny]){
            dfs(nx,ny,mp[nx][ny]);
        }
    }
}
bool cmp(pair<int,char>a,pair<int,char>b){
    if(a.first == b.first)return a.second < b.second;
    return a.first > b.first;
}
signed main(){
    int t;
    cin >> t;
    for(int C = 1; C <= t; C++){
        cin >> n >> m;
        map<char,int>alphamp;
        memset(visit,0,sizeof(visit));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mp[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visit[i][j]){
                    dfs(i,j,mp[i][j]);
                    alphamp[mp[i][j]]++;
                }
            }
        }
        vector<pair<int,char>>st;
        cout << "World #" << C << '\n';
        if(n == 0 || m == 0)continue;
        for(auto i: alphamp){
            st.emplace_back(make_pair(i.second,i.first));
        }
        sort(st.begin(),st.end(),cmp);
        for(int i = 0; i < st.size(); i++){
            cout << st[i].second << ": " << st[i].first << "\n";
        }
    }
}