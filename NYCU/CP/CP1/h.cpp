//Sim
#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int MAXN = 1e4+5;
ld c[105];
ld d[105];
signed main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        list<char>ls;
        string s;
        auto it = ls.end();
        getline(cin,s);
        bool flag = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '<'){
                if(it != ls.begin()){
                    it = ls.erase(--it);
                }
            }else if(s[i] == '['){
                it = ls.begin();
            }else if(s[i] == ']'){
                it = ls.end();
            }else{
                it = ls.insert(it,s[i]);
                it++;
            }
        }
        for(auto i : ls)cout << i;
        cout << '\n';
    }

}