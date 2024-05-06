//Sheba's Amoebas
#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[105][105];
int xd[8] = {-1,-1,-1,0,0,1,1,1};
int yd[8] = {-1,0,1,-1,1,-1,0,1};
void dfs(int x,int y){
    if(x < 0 || y < 0 || x >= n || y >= m)return;
    if(a[x][y] == '.')return;
    a[x][y]='.';
    for(int i = 0; i < 8; i++){
        dfs(x+xd[i],y+yd[i]);
    }
    

}
signed main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int  j =0 ; j < m; j++){
            if(a[i][j] == '#'){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans;
}