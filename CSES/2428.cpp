#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =2e5+5;
int a[MAXN];

signed main(){
    int k,n;
    map<int,int>mp;
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> a[i];
    int j = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(j < n && (((int)mp.size() < k) || (mp.count(a[j]) > 0))){
            mp[a[j]]++;
            j++;
        }
        ans += (j - i);
        mp[a[i]]--;
        if(mp[a[i]] == 0)mp.erase(a[i]);
    }
    cout << ans << '\n';
}