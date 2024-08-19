#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<pair<int,int>>v(n,pair<int,int>());
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    vector<int>tmp;
    for(int i = 0; i < n; i++){
        int idx = upper_bound(tmp.begin(),tmp.end(),v[i].second)-tmp.begin();
        if(idx == tmp.size() || tmp.back() == v[i].second)tmp.push_back(v[i].second);
        else tmp[idx] = v[i].second;
    }
    cout << tmp.size();
}