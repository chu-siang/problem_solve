#include<bits/stdc++.h>
using namespace std;

int r[10][10],c[10][10],b[10][10],cnt = 0,g[10][10];

void dfs(int x, int y){
    if(x == 9){
        cnt++;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << g[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
        return ;
    }
    if (g[x][y]){
        if (y == 8) dfs(x+1, 0);
        else dfs(x, y+1);
        return;
    }
    for(int i = 1; i <= 9; i++){
        if(!r[x][i] && !c[y][i] && !b[x/3*3+y/3][i]){
            r[x][i] = 1;
            c[y][i] = 1;
            b[x/3*3+y/3][i] = 1;
            g[x][y] = i;
            if(y == 8)dfs(x+1,0);
            else dfs(x,y+1);
            r[x][i] = 0;
            c[y][i] = 0;
            b[x/3*3+y/3][i] = 0;
            g[x][y] = 0;
        }
    }
}



int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> g[i][j];
            if(g[i][j]){
                r[i][g[i][j]] = 1;
                c[j][g[i][j]] = 1;
                b[(i/3)*3+j/3][g[i][j]] = 1;
            }
        }
    }
    dfs(0,0);
    cout << "there are a total of " << cnt << " solution(s).\n";
}