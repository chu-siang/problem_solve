//uva Mine Sweeper 10279
#include<bits/stdc++.h>
using namespace std;
int a[11][11];
char mp[11][11];
char ansmp[11][11];
int dx[8] = {0,0,-1,-1,-1,1,1,1};
int dy[8] = {-1,1,-1,0,1,-1,0,1};
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cin.ignore();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mp[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int ans = 0;
                if(mp[i][j] == '*'){
                    a[i][j] = -1;
                    continue;
                }
                for(int x = 0; x < 8; x++){
                    if(i+dx[x] < 0 || j + dy[x] < 0 || i + dx[x] >= n || j + dy[x] >= n)continue;
                    if(mp[i+dx[x]][j+dy[x]] == '*')ans++;
                }
                a[i][j] = ans;
            }
        }
        char c;
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> c;
                if(c == 'x'){
                    if(a[i][j] == -1){
                        flag = true;
                    }
                    ansmp[i][j] = (char)(a[i][j]+'0');
                }else ansmp[i][j] = '.';
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(flag && mp[i][j] == '*')cout << '*';
                else cout << ansmp[i][j];
            }
            cout << '\n';
        }
        if(t)cout << '\n';
    }
}