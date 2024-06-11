//uva10189 Minesweeper
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
char a[105][105];
int mp[105][105];
int dx[8]= {0,0,1,1,1,-1,-1,-1};
int dy[8]= {-1,1,-1,0,1,0,-1,1};
signed main(){
    int k = 0;
    bool flag = false;
    while(cin >> n >> m){
        if(n == m&&n == 0)break;
        memset(mp,0,sizeof(mp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                if(a[i][j] == '*'){
                    mp[i][j] = -1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == '*')continue;
                for(int x = 0; x < 8; x++){
                    if(i+dx[x] < 0 || i+dx[x] >= n || j +dy[x] < 0 || j + dy[x] >= m)continue;
                    if(a[i+dx[x]][j+dy[x]] == '*')mp[i][j]++;
                }
            }
        }
        if(flag)cout << '\n';
        flag = true;
        cout <<"Field #"<< ++k << ":\n";    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mp[i][j] == -1)cout << '*';
                else cout << mp[i][j];
            }
            cout << "\n";
        }

    }

}
/*
4 4
*...
....
.*..
....

*/