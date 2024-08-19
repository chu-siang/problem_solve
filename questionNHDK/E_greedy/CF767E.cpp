#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5+5;
// struct Node{
//     int pos,w;
//     bool operator < (const Node & Nd) const {
//         return Nd.w > w;
//     }
// }Nd[MAXN];
struct cmp{
    bool operator () (const pair<int,int> &a,const pair<int,int>&b) const{
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};/*
bool operator < (const pair<int,int> a,const pair<int,int> b) {
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}*/
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
int a[MAXN],note[MAXN],coin[MAXN],w[MAXN];
signed main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        note[i] = a[i]/100;
        coin[i] = a[i]%100;
        a[i]%=100;
    }
    for(int i = 0; i < n; i++)
        cin >> w[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i])q.push({i,(100-a[i])*w[i]});
        if(m < a[i]){
            m+=100;
            ans += q.top().second;
            note[q.top().first]++;
            coin[q.top().first] = 0;
            q.pop();
        }
        m-=a[i];
    }
    cout << ans << '\n';
    for(int i = 0; i < n; i++){
        cout << note[i] << ' ' << coin[i] << '\n';
    }
}