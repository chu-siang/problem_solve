#include<bits/stdc++.h>
using namespace std;

int g[6][6] = {0};

int save[9];

void dfs(int s,int n, int d,int e){
    if(d == e){
        for(int i = 0; i < e; ++i){
            cout << save[i];
        }
        cout << s << endl;
        return;
    }

    save[d] = s;
    for(int i = 1; i <= n; i++){
        if(g[s][i]){
            g[s][i] = 0;
            g[i][s] = 0;
            dfs(i,n, d+1,e);
            g[s][i] = 1;
            g[i][s] = 1;
        }
    }
}

int main(){
    g[1][2] = g[2][1] = 1;
    g[1][3] = g[3][1] = 1;
    g[1][5] = g[5][1] = 1;
    g[2][3] = g[3][2] = 1;
    g[2][5] = g[5][2] = 1;
    g[3][4] = g[4][3] = 1;
    g[3][5] = g[5][3] = 1;
    g[4][5] = g[5][4] = 1;
    dfs(1,5,0,8);
}