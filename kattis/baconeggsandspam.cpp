#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;


signed main(){
    int n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n, n){
        string s;
        string name;
        map<string,vector<string>> m;
        cin.ignore();
        for(int i = 0; i < n; ++i){
            getline(cin,s);
            stringstream ss(s);
            string tmp;
            while(ss >> s){
                if(name == ""){
                    name = s;
                }else{
                    m[s].emplace_back(name);
                }
            }
            ss.clear();
            ss.str("");
            name = "";
        }
        for(auto it : m){
            set<string>st;
            for(auto na : it.second){
                st.emplace(na);
            }
            cout << it.first << ' ';
            for(auto & nt : st){
                cout << nt << ' ';
            }
            st.clear();
            cout << '\n';
        }
        cout << '\n';
        m.clear();
    }

}