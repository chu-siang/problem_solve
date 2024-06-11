#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>>v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }
        map<double,int>mp;
        map<int,int>horizontal,vertical;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[j].first-v[i].first == 0){
                    if(v[j].second-v[i].second != 0)vertical[v[j].first]++;
                    
                }else if(v[j].second-v[i].second == 0){
                    if(v[j].first-v[i].first != 0)horizontal[v[j].second]++;
                }
                else mp[(double)(v[j].second-v[i].second)/(double)(v[j].first-v[i].first)]++;
            }
        }
        cout << (mp.size()+horizontal.size()+vertical.size()) << '\n';
        mp.clear();
        horizontal.clear(),vertical.clear();
    }
}