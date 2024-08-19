//two pointer
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MiruSort ios_base::sync_with_stdio(0); cin.tie(0);

const int MOD = 1e9 + 7; 
const int maxn = 1e5 + 5;
int cnt1[27], cnt2[maxn][27];

bool ok(int l, int r){
    for(int i = 0; i < 27; ++i)
        if(cnt1[i] < cnt2[r][i] - cnt2[l - 1][i])
            return false;
    return true;
}

signed main(){
    MiruSort
    int n, m;
    cin >> n >> m;
    string dic, target;
    cin >> target;
    cin >> dic;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 27; ++j){
            if(target[i - 1] - 'a' == j)
                cnt2[i][j] = cnt2[i - 1][j] + 1;
            else
                cnt2[i][j] = cnt2[i - 1][j];
        }
    }
    for(int i = 0; i < m; ++i)
        cnt1[dic[i] - 'a']++;
    int l = n, r = n;
    ll ans = 0;
    while(l > 0 && r > 0){
        if(ok(l, r)){
            if(l == 1){
                ans += r;
                r--;
                continue;
            }
            l--;
        }
        else{
            ans += r - l;   
            r--;
        }
    }
    cout << ans << '\n';
    return 0;
}