#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first == b.first)return a.second < b.second;
    return a.first < b.first;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        int m;
        cin >> m;
        vector<pair<int,int>>v;
        while(cin >> a >> b){
            if(a==0&&b==0)break;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        int now = 0,ind = 0;
        bool flag = false;
        vector<pair<int,int>>ans;
        while(true){
            int mx = ind;
            while(ind < v.size() && v[ind].first <= now){
                if(v[ind].second >= v[mx].second)mx = ind;
                ind++;
            }
            if(v[mx].second <= now){
                cout << '0' << '\n' << '\n';
                flag = true;
                break;
            }
            now = v[mx].second;
            ans.push_back(v[mx]);
            if(now >= m)break;
        }
        if(flag)continue;
        cout << ans.size() << '\n';
        for(auto i:ans)cout << i.first << ' ' << i.second<< '\n';
        cout << '\n';
    }
}