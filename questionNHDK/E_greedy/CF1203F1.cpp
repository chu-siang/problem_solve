#include<bits/stdc++.h>
#define int long long
using namespace std;

pair<int,int>p[500];

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first+a.second > b.first+b.second;
}

signed main(){
    int n,r;
    cin >> n >> r;
    vector<pair<int,int>>pos,neg;
    for(int i = 0; i < n; i++){
        pair<int,int>tmp;
        cin >> tmp.first >> tmp.second;
        if(tmp.second < 0){
            neg.emplace_back(tmp);
        }else pos.emplace_back(tmp);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end(),cmp);
    for(auto i : pos){
        if(r < i.first){
            cout << "NO";
            return 0;
        }
        r += i.second;
    }
    for(auto i : neg){
        if(r < i.first || r + i.second < 0){
            cout << "NO";
            return 0;
        }
        r+=i.second;
    }
    cout <<"YES";
}