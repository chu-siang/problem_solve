#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int MAXN = 3e5+5;
int a[105][105];
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    int n;
    cin >> n;
    int ans = -1e18;
    //i,j長寬 xy起點
    int c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c;
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + c;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int x = i; x <= n; x++){
                for(int y = j; y <= n; y++){
                    ans = max(ans,a[x][y] - a[i-1][y] - a[x][j-1] + a[i-1][j-1]);
                }
            }
        }
    }
    cout << ans << '\n';
}
