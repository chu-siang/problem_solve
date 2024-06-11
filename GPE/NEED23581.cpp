#include<bits/stdc++.h>
using namespace std;

signed main(){
    string s;
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        string a = s+s;
        string cmp = s;
        int idx = 0;
        for(int i = 1; i < s.size(); i++){
            string tmp = a.substr(i,s.size());
            if(tmp < s){
                s = tmp;
                idx = i;
            }
        }
        cout << idx+1 << '\n';
    }
}