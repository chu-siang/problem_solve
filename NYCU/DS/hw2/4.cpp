#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n,idx = 15000;
    string s;
    cin >> n;
    //cin.ignore();
    cin >> s;
    string ans = s;
    string stdard_ans = s;
    sort(stdard_ans.begin(),stdard_ans.end());
    for(int k = 1; k <= n; k++){
        string tmp = s;
        for(int i = 0; i + k - 1 < n; i++){
            int l = i, r = i + k - 1;
            for(int j = 0; j < (r - l + 1) / 2;++j){
                swap(tmp[l + j],tmp[r - j]);
            }
        }
        if(ans >= tmp){
            if(ans > tmp)idx = k;
            else idx = min(idx,k);
            ans = tmp;
        }
    }
    cout << ans << '\n' << idx << '\n';
}