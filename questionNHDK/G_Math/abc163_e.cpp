#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6+5;
int n,k;
int a[505],b[505];


bool check(int x){
    int tot = 0;
    for(int i = 0; i < n; i++)b[i] = a[i]%x,tot+=b[i];
    sort(b,b+n);
    int tmp = 0;
    tot/=x;
    for(int i = 0; i < n-tot; i++)tmp+=b[i];
    for(int i = n - tot; i < n; i++)tmp+=x-b[i];
    return tmp <= (2*k);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    set<int>st;
    int sum = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> a[i],sum+=a[i];
    int ans = 0;
    for(int i = 1; i*i <= 1e12; i++){
        if(sum % i == 0){
            st.emplace(i);
            st.emplace(sum/i);
        }
    }
    for(auto i : st){
        if(check(i))ans = max(i,ans);
    }
    cout << ans;
}