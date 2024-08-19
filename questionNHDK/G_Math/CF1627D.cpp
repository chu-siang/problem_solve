#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e6+5;
const int MOD = 1e9+7;
int st[MAXN];
bool prime[MAXN];
vector<int>PR;
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        st[x] = 1;
        mx = max(mx,x);
    }
    int cnt = 0;
    for(int i = 1; i <= mx; i++){
        int gcd = 0;
        for(int j = i; j <= mx; j+=i)
            if(st[j])gcd = __gcd(gcd,j);
        if(gcd == i)cnt++;
    }
    cout << cnt - n << '\n';
}
