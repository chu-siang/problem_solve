//uva 11398 a090
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll bin(string s){
    ll ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans *= 2;
        ans += (s[i]-'0');
    }
    return ans;
}

int main(){
    string s;
    bool flag = false;
    ll cnt = 0;
    string ans="";
    while(cin >> s){
        if(s == "~")break;
        if(s == "")continue;
        if(s == "#"){
            cout << bin(ans) << '\n';
            flag = false;
            ans = "";
        }
        int l = s.length();
        if(l == 1)flag = 1;
        else if(l == 2) flag = 0;
        else {
            for(int i = 0; i < l - 2; i++)ans +=('0'+flag);
        }
    }
}