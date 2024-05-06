//permcode
#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    while(cin >> t,t){
        string s,p,m;
        cin >> s >> p >> m;
        map<char,int>mpp,mps;
        for(int i = 0; i < s.size();i++){
            mps[s[i]] = i;
        }
        for(int i = 0; i < p.size();i++){
            mpp[p[i]] = i;
        }
        int n = m.size();
        int d = ((int)pow((double)n,1.5)+t)%n;
        string c = "";
        vector<int>v(n);
        vector<char>ans(n);
        ans[d] = p[mps[m[d]]];
        for(int i = d-1; i >= 0; i--){
            ans[i] = p[mps[m[i]]^mps[ans[(i+1)%n]]];
        }
        for(int i = n-1; i > d; i--){
            ans[i] = p[mps[m[i]] ^ mps[ans[(i+1)%n]]];
        }
        mpp.clear(),mps.clear();
        for(auto i: ans)cout << i;
        cout << '\n';
    }
    
}