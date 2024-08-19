#include<bits/stdc++.h>
#define MAXN 200005
#define int long long
using namespace std;

int x[MAXN];

signed main(){
    int n, l;
    cin >> n >> l;
    set<int> st;
    int ans = 0;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        x[b] = a;
    }
    st.emplace(0);
    st.emplace(l);
    for(int i = 1; i < n; i++){
        int pre = *st.lower_bound(x[i]);
        int nxt = *--st.upper_bound(x[i]);
        ans += (pre - nxt);
        st.emplace(x[i]);
    }
    cout << ans <<endl;
}