
#include <bits/stdc++.h>



#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b, c) for (int i = a; i < b; i += c)
#define Each(i, v) for (auto& i : v)

#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 1e6 + 1;



ll ans[maxn];

ll scan(ll row, ll l, ll r) {
    ll mx = 0, pos = 0;
    FOR(i, l, r+1, 1) {
        int val = GetVal(row, i);
        if (val > mx) mx = val, pos = i;
    }
    ans[row] = pos;
    return pos;
}

void dfs(ll u, ll d, ll l, ll r) {
    if (u > d || l > r) return;
    ll mid = (u+d) / 2;
    ll pos = scan(mid, l, r);
    dfs(u, mid-1, l, pos-1);
    dfs(mid+1, d, pos+1, r);
}


void solve(int n, int m) {
    memset(ans, 0, sizeof(ans));
    dfs(1, n, 1, m);
    FOR(i, 1, n+1, 1) Report(ans[i]);
}

/*




 */