//uva 10908Largest square
#include<bits/stdc++.h>
using namespace std;
char mp[105][105];
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {-1,1,-1,0,1,-1,0,1};
signed main(){
    int t;
    cin >> t;
    int n,m,q;
    while(t--){
        cin >> n >> m >> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mp[i][j];
            }
        }
        cout << n << ' ' << m  << ' ' << q << '\n';
        while(q--){
            int x,y;
            cin >> x >> y;
            int ans = 1;
            for(int r = 1; x+r < n && y+r < m; r++){
                bool flag = true;
                for(int i = x-r; i <= x+r; i++){
                    for(int j = y-r; j <= y+r; j++){
                        if(i >= n || y >= m || i < 0 || y < 0||
                            mp[i][j] != mp[x][y]){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag)break;
                }
                if(flag)ans = 2*r+1;
                else break;
            }
            cout << ans << '\n';
        }
    }
}