#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    vector<string> vstring (m);
    for(int i = 0; i < m; i++){
        cin >> vstring[i];
    }
    int ans = 0;
    set<string> unorderset(vstring.begin(),vstring.end());
    for(auto &s: unorderset){
        for(int len = 1; len + len < s.size(); len++){
            string p = s.substr(0,len) , q = s.substr(s.size()-len);
            if(p != q) continue;
            string y = s.substr(len, s.size()-len-len);
            if(unorderset.count(y)){
                ans++;
            }   
        }
    }
    cout << ans << '\n';

}