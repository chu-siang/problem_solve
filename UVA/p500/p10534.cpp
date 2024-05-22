#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    while(cin >> n){
        vector<int>v(n);
        for(int i = 0; i < n; i++)cin >> v[i];
        vector<int>lis(n),lds(n);
        vector<int>tmp;
        for(int i = 0; i < n; i++){
            size_t it = lower_bound(tmp.begin(),tmp.end(),v[i])-tmp.begin();
            if(it == tmp.size() || tmp.empty())tmp.push_back(v[i]);
            else tmp[it] = v[i];
            lis[i] = tmp.size();
        }
        tmp.clear();
        for(int i = n-1; i >= 0; i--){
            size_t it = lower_bound(tmp.begin(),tmp.end(),v[i])-tmp.begin();
            if(it == tmp.size() || tmp.empty())tmp.push_back(v[i]);
            else tmp[it] = v[i];
            lds[i] = tmp.size();
        }
        int mn = 0;
        for(int i = 0; i < n; i++){
            mn = max(mn,min(lis[i],lds[i]));
        }
        cout << mn*2-1 << '\n';
    }
}