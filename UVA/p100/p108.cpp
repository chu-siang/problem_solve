#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[105][105];

int main(){
    int n;
    ll num;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> num;
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]+num;
        }
    }
    ll ans = -127*100*101;
    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= n; y++){
            for(int i = x; i <= n; i++){
                for(int j = y; j <= n; j++){
                    ans = max (ans, arr[i][j] - arr[i][y-1] - arr[x-1][j] + arr[x-1][y-1]);
                }
            }
        }
    }
    cout << ans << '\n';
}
/*
4
0 -2  -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
*/