#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        int m;
        cin >> m;
        vector<pair<int,int>>v;
        while(cin >> a >> b){
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
            if(ind == v.size() || v[ind].second <= now){
                cout << '0' << '\n';
                flag = true;
                break;
            }
            now = v[ind].second;
            ans.push_back(v[ind]);
            if(now >= m)break;
        }
        if(flag)continue;
        cout << ans.size();
        for(auto i:ans)cout << i.first << ' ' << i.second<< '\n';
        
    }
}