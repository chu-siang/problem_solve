#include<bits/stdc++.h>
#define int long long
using namespace std;

string a = "A...3..HIL.JM.O...2TUVWXY5";
string num = "1SE.Z..8.";
signed main(){
    string s;
    map<char,char>mp;
    for(int i = 0; i < a.size(); i++){
        mp[(char)('A'+i)]= a[i];
    }
    for(int i = 0; i < num.size(); i++){
        mp['0'+(i+1)] = num[i];
    }
    while(cin >> s){
        bool f1 = true;//pali
        bool f2 = true;//mirr
        int l = s.size();
        if(l&1){
            if(mp[s[l/2]]=='.')f2 = false;
        }
        for(int i = 0; i < l/2; i++){
            if(s[i] != s[l-i-1]){
                f1 = false;
            }
            if((s[i]!=mp[s[l-i-1]]) || mp[s[i]] == '.' || mp[s[l-i-1]]=='.')f2 = false;
        }
        cout << s;
        if(f1 && f2)cout << " -- is a mirrored palindrome.";
        else if(f1)cout << " -- is a regular palindrome.";
        else if(f2)cout << " -- is a mirrored string.";
        else cout << " -- is not a palindrome.";
        cout << '\n';
    }
    return 0;
}