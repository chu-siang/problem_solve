#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    cin.ignore();

    while(t--){
        list<char>l;
        string s;
        getline(cin,s);
        auto it = l.begin();
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '['){
                it = l.begin();
            }else if(s[i] == ']'){
                it = l.end();
            }else if(s[i] == '<'){
                if(!l.empty() && it!= l.begin()){
                    --it;
                    // cout << "before delete it : ";
                    // for(auto c : l)cout << c;
                    // cout << '\n';
                    // cout << "debug when in " << i << " it : " << *it << '\n';
                
                    it = l.erase(it);
                }
            }else{
                it = l.emplace(it,s[i]);
                it++;
            }
        }
        for(auto c : l)cout << c;
        if(t)cout << '\n';
    }
}