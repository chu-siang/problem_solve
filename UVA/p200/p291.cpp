#include<bits/stdc++.h>
using namespace std;

int save[9];

bool visit[6][6] = {false};
void dfs(int s,int n,int d,int e){
    if(d == e){
        for(int i = 0; i < d; i++){
            cout << save[i];
        }
        cout << s << '\n';
        return ;
    }
    save[d] = s;
    for(int i = 1; i <= n; i++){
        if(visit[s][i]){
            visit[s][i] = 0;
			visit[i][s] = 0;
            dfs(i,n,d+1,e);
            visit[s][i] = 1;
			visit[i][s] = 1;
        }
    }
}

int main(){
    visit[1][2] = visit[2][1] = true;
    visit[1][3] = visit[3][1] = true;
    visit[1][5] = visit[5][1] = true;
    visit[2][3] = visit[3][2] = true;
    visit[2][5] = visit[5][2] = true;
    visit[3][4] = visit[4][3] = true;
    visit[3][5] = visit[5][3] = true;
    visit[4][5] = visit[5][4] = true;
	dfs(1,5,0,8);
	return 0;
}