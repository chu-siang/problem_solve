#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int mp[25][25];
int H,W,a,b;

bool valid(int x,int y){
    return !mp[x][y] && 0 =< x && x < H && y >= 0 && y < W;
}

void dfs(int i, int j, int usedA, int usedB){
    if((usedA<<1) + usedB == h*w){
        ans++;
        return ;
    }

    if(i == h) return;
    int ni,nj;
    if(j == w - 1) ni = i + 1, nj = 0;
    else ni = i, nj = j + 1;
    
    if(mp[i][j]){
        dfs(ni, nj, usedA, usedB);
        return;
    }

    mp[i][j] = true;

    if(useA < a){
        if(valid(i,j+1)){
            mp[i][j + 1] = true;
            dfs(ni,nj,usedA + 1, usedB);
            mp[i][j + 1] = false;
        }
        if(valid(i + 1, j)){
            mp[i + 1][j] = true;
            dfs(ni,nj,usedA + 1,usedB);
            mp[i + 1][j] = false;
        }
    }
    if(usedB < b){
        dfs(ni,nj,usedA,usedB+1);
    }
    mp[i][j]=false;
}

int main(){
    cin >> H >> W >> a >> b;
    dfs(0,0,0,0);
    cout << ans;
    return 0;
}