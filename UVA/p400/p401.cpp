#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<char,char>mp;
bool palidrome(string s){
    int len = s.length();
    for(int i = 0; i < (len/2); i++){
        if(s[i] != s[len - i - 1])return false;
    }
    return true;
}

bool mirrored(string s){
    int len = s.length();
    for(int i = 0; i <= (len/2); i++){
        if(mp[s[i]] != s[len - i - 1])return false;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    string s1 = "AEHIJLMOSTUVWXYZ12358";
    string s2 = "A3HILJMO2TUVWXY51SEZ8";
    int l = s1.length();
    for(int i = 0; i < l; i++)mp[s1[i]] = s2[i];
    bool flag = false;
    while(cin >> s){
        bool p = palidrome(s);
        bool m = mirrored(s);
        cout << s <<" -- ";
        if(p&&m)cout << "is a mirrored palindrome.";
        else if(p)cout << "is a regular palindrome.";
        else if(m)cout << "is a mirrored string.";
        else cout << "is not a palindrome.";
        cout << "\n\n";
    }
}