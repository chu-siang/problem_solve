#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    string s;
    string s1[4] = {
        "`1234567890-=",
        "QWERTYUIOP[]\\",
        "ASDFGHJKL;'",
        "ZXCVBNM,./"
    };
    map<char,char>mp;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j < s1[i].size(); j++){
            mp[s1[i][j]] = s1[i][j-1];
        }
    }
    bool flag = false;
    while(getline(cin,s)){
        flag = true;
        int l = s.length();
        for(int i = 0; i < l; i++){
            if(mp[s[i]])cout << mp[s[i]];
            else cout << s[i];
        }
        cout << '\n';
    }
}