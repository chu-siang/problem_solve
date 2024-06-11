#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,q;
char mp[105][105];
signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n >> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> mp[i][j];
            }
        }
        cout << m << ' ' << n << ' ' << q << '\n';
        while(q--){
            int r,c;
            cin >> r >> c;
            int ans = 1;
            for(int l = 1; r + l< m &&  c+l < n; l++){
                bool flag = true;
                for(int i = r-l; i <=  r+l; i++){
                    for(int j = c-l; j <= c+l; j++){
                        if(i < 0 || i >= m || j < 0 || j >= n ||
                            mp[i][j] != mp[r][c]){
                                flag = false;
                                break;
                            }
                    }
                    if(!flag)break;
                }
                if(flag)ans = 2*l+1;
                else break;
            }
            cout << ans << '\n';
        }
    }
}