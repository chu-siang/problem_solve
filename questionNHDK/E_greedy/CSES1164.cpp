#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    vector<int> RoomAssigned(n,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int room = 1;
    for(int i = 0; i < n; i++){
        if(pq.size() == 0){
            RoomAssigned[v[i].second] = room++;
            pq.push({v[i].first.second,room-1});
        }else if(pq.top().first < v[i].first.first){
            pair<int,int>p = pq.top();
            pq.pop();
            RoomAssigned[v[i].second] = p.second;
            pq.push({v[i].first.second,p.second});
        }else{
            RoomAssigned[v[i].second] = room++;
            pq.push({v[i].first.second,room-1});
        }
    }
    cout << room-1 << '\n';
    for(int i = 0; i < n; i++){
        cout << RoomAssigned[i] << " "[i == n-1];
    }
}