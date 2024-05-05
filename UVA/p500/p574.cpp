#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[14];

signed main(){
    int t,n;
    while(cin >> t >> n){
        if(t == 0 && n == 0)break;
        for(int i = 0; i < n; i++)cin >> a[i];
        sort(a,a+n,greater<int>());
        cout << "Sums of " << t << ":\n";
        set<vector<int>,greater<vector<int>>>ans;
        int cnt = 0;
        for(int i = 0; i < (1 << n); i++){
            int sum = 0,j;
            bool flag = false;
            vector<int>tmp;
            for(int j = 0; j < n; j++){
                if(i&(1 << j)){
                    sum += a[j];
                    tmp.push_back(a[j]);
                }
            }
            if(sum == t){
                ans.emplace(tmp);
            }
        }
        if(ans.size() == 0){
            cout << "NONE\n";
            continue;
        }
        for(auto i : ans){
            auto j = i;
            for(int k = 0; k < j.size(); k++){
                cout << j[k] << "+\n"[k == j.size()-1];
            }
        }
    }
}