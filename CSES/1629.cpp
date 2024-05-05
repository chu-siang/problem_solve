#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+5;
pair<int,int>p[MAXN];
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p,p+n,cmp);
    int cnt = 0;
    int now = 0;
    for(int i = 0; i < n; i++){
        if(p[i].first >= now){
            now = p[i].second;
            cnt++;
        }
    }
    cout << cnt << '\n';
}