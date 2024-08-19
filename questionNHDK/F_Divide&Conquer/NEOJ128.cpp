
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1025;
int ans[MAXN][MAXN];
void dfs(int n, int l, int r, int tr, int tc) {
    if (n == 1) {
        ans[tr][tc] = l;
        return;
    }
    if ((r-l+1) % 2) {
        int m1 = (l+r-1)/2;
        int m2 = m1+n/2;
        dfs(n/2, l, m1, tr, tc);
        dfs(n/2, l, m1, tr+n/2, tc+n/2);
        dfs(n/2, m1+1, m2, tr+n/2, tc);
        dfs(n/2, m2+1, r, tr, tc+n/2);
    } else {
        int m = l + n/2 - 1;
        dfs(n/2, l, m, tr, tc);
        dfs(n/2, l, m, tr+n/2, tc+n/2);
        dfs(n/2, m+1, r, tr+n/2, tc);
        dfs(n/2, m+1, r, tr, tc+n/2);
    }
}

void solve(int N) {
    dfs(N, 1, 2*N-1, 1, 1);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            Report(ans[i][j]);
        }
    }
    return ;
}