//leetcode Min Cost to Connect All Points
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1005;
pair<int,int>p[MAXN];
int dis[MAXN];
signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> p[i].first  >> p[i].second;
    int ans = 0;
    fill(dis,dis+MAXN,1e9);
    int k = n-1;
    int j = 0;
    while(k--){
        int mini = j;
        dis[j] = INT_MAX;
        for(int i = 0; i < n; i++){
            if(dis[i] != INT_MAX){
                dis[i] = min(dis[i],abs(p[j].first-p[i].first)+abs(p[j].second-p[i].second));
                mini = ((dis[i] < dis[mini])?i:mini);
            }
        }
        j = mini;
        ans += dis[j];
    }
    cout << ans << '\n';
}