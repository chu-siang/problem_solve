#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+5;
pair<int,int>p[MAXN];

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second > b.second;
}


signed main(){
    int now = 0;
    int n;
    while(cin >> n,n){
        for(int i = 0; i < n; i++)cin >> p[i].first >> p[i].second;
        sort(p,p+n,cmp);
        int sum = 0,tmp = 0;
        for(int i = 0; i < n; i++){
            tmp += p[i].first;
            sum = max(sum,tmp+p[i].second);
        }
        cout << sum << '\n';
    }
}