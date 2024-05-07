#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string str;
    string s[8] = {"~!@#$%^&*()_+",
                    "`1234567890-=",
                    "qwertyuiop[]\\",
                    "QWERTYUIOP{}|",
                    "asdfghjkl;\'",
                    "ASDFGHJKL:",
                    "zxcvbnm,./",
                    "ZXCVBNM<>?"};
        map<char,char>mp;
        for(int i = 0; i < 8; i++){
            int l = s[i].length();
            for(int j = 2; j < l; j++){
                if(isalpha(s[i][j-2]))
                    mp[s[i][j]] = tolower(s[i][j - 2]);
                else mp[s[i][j]] = s[i][j-2];
            }
        }
    while(getline(cin,str)){
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' ') cout << ' ';
            else cout << mp[str[i]]; 
        }
        cout << '\n';
    }
    return 0;
}