#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll bin(string s){
    ll num = 0;
    int l = s.length();
    for(int i = 0; i < l; i++){
        num *= 2;
        num += (s[i]-'0');
    }
    return num;
}

int main(){
    string s;
    string ans = "";
    bool flag = false;
    while(cin >> s){
        if(s == "~")break;
        if(s == "")continue;
        if(s == "#"){
            cout << bin(ans) << '\n';
            ans = "";
            flag = false;
        }
        int l = s.length();
        if(l == 1)flag = 1;
        else if(l == 2) flag = 0;
        for(int i = 0; i < l-2; i++)ans += ('0'+flag);
    }
}