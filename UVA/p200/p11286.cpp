#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    while(cin >> n,n){
        int c;
        map<set<int>,int>mp;
        int mx = 0;
        for(int i = 0; i < n; i++){
            set<int>st;
            for(int j = 0; j < 5; j++){
                cin >> c;
                st.emplace(c);
            }
            mp[st]++;
            mx = max(mx,mp[st]);
        }
        int cnt = 0;
        for(auto i:mp){
            if(i.second == mx)cnt+=mx;
        }
        cout << cnt << '\n';
    }
}