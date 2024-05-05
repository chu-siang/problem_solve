#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[110] = {0};

int main(){
    string s1,s2,s;
    ll t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--){
        getline(cin,s1);
        getline(cin,s2);
        int len = s1.length();
        map<char,char>mp;
        for(int i = 0; i < len; i++){
            mp[s1[i]] = s2[i];
        }
        cout << s2 << '\n' << s1 << '\n';
        while(getline(cin,s)){
            if(s == "")break;
            for(int i = 0; i < s.length(); i++){
                if(mp[s[i]])cout << mp[s[i]];
                else cout << s[i];
            }
            cout << '\n';
        }
        if(t)cout << '\n';
        mp.clear();
    }

}