//Bacon,Eggs,and Spam
#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    while(cin >> n,n){
        string name,s;
        map<string,set<string>>mp;
        for(int i = 0; i < n; i++){
            cin >> name;
            getline(cin,s);
            stringstream ss(s);
            ss << s;
            while(ss >> s){
                mp[s].insert(name);
            }
        }
        for(auto i : mp){
            cout << i.first;
            for(auto j : i.second){
                cout << ' ' << j;
            }
            cout << '\n';
        }
        cout << '\n';
    }
    
}