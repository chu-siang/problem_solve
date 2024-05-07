#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    bool flag = false;
    while(cin >> n){
        if(flag)cout << '\n';
        flag = true;
        string s;
        map<string,int>mp;
        set<string>st;
        while(cin >> s){
            if(s == "EndOfText")break;
            for(int i = 0; i < s.size();i++){
                if(s[i] >='A'&&s[i] <='Z')s[i] = tolower(s[i]);
                if(s[i] > 'z' || s[i] < 'a'){
                    s[i] = ' ';
                }
            }
            stringstream ss(s);
            while(ss >> s){
                mp[s]++;
            }
            ss.clear();
            ss.str("");
        }
        for(auto i:mp){
            if(i.second == n)st.emplace(i.first);
        }
        for(auto i:st)cout << i << '\n';
        if(st.empty())cout << "There is no such word.\n";
    }
}