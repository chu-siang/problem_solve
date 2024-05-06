//backspace
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s;
    cin >> s;
    list<char>ls;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '<'){
            if(!ls.empty())continue;
            else ls.pop_back();
        }else ls.push_back(s[i]);
    }
    for(auto i:ls)cout << i;
}