#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int MAXN = 105;

int g[MAXN][MAXN];
int steps[MAXN][MAXN];
int dr[] = {1, 0, 0,-1};
int dc[] = {0, 1,-1, 0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int S;
    int Case = 1;
    while(cin >> S){
        int n,m,r,c,nr,nc;
        cin >> n >> m;
        memset(g,0,sizeof(g));
        memset(steps,0,sizeof(steps));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j];
        for(int j = 0; j < m; j++)
            if(g[0][j] == 1){
                r = 0;
                c = j;
            }
        queue<pair<int,int>>q;
        q.push({r,c});
        steps[r][c] = 1;
        while(!q.empty()){
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for(int i = 0; i < 5 - S; i++){
                nr = r + dr[i];
                nc = c + dc[i];
                if(g[nr][nc] == 0)continue;
                if(steps[nr][nc] > 0) continue;
                if(nr < 0 || nr >= n || nc >= m || nc < 0)continue;
                steps[nr][nc] = steps[r][c] + 1;
                q.push({nr,nc});
            }
        }
        cout << "Case " << Case++ << ":\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << steps[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}
