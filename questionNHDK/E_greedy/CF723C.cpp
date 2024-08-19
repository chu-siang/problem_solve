#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =2e4;
int a[MAXN];

signed main(){
    int n,m;
    cin >> n >> m;
    map<int,int>mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] <= m)mp[a[i]]++;
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        if(mp[i] < n/m){
            for(int j = 0; j < n; j++){
                if(mp[i] < n/m){
                    if(a[j] > m){
                        a[j] = i;
                        mp[i]++;
                        cnt++;
                    }else if(mp[a[j]] > n/m){
                        mp[a[j]]--;
                        a[j] = i;
                        cnt++;
                        mp[i]++;
                    }
                }
            }
        }
    }
    cout << n/m << ' ' <<cnt << '\n';
    for(int i = 0; i < n; i++)cout << a[i] << " "[i==n-1];
}