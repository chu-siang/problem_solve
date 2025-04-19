#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6+5;
int a[MAXN];

bool isAlpha(char c){
    if(c >= 'a' && c <= 'f') return true;
    if(c >= 'A' && c <= 'F') return true;
    if(c >= '0' && c <= '9') return true;
    return false;
}
int fun(char c){
    if(c >= 'a' && c <= 'f')return c-'a'+10;
    if(c >= 'A' && c <= 'F')return c-'A'+10;
    return c-'0';
}
int trans(string s){
    int tmp = 0;
    int l = s.size();
    for(int i = 0; i < l; ++i){
        tmp *= 16;
        tmp += fun(s[i]);
    }
    return tmp;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    map<string,int>mp;
    vector<string>v;
    string tmp = "";
    while(getline(cin,s)){
        int n = s.size();
        bool flag = 0;
        int cnt = 0;
        for(int i = 1; i < n; ++i){
            if(s[i-1] == '0' && (s[i] == 'X' || s[i] == 'x')){
                flag = 1;
                cnt = 0;
                tmp += s[i-1];
                tmp += s[i];
                continue;
            }else if(flag && cnt < 8){
                if(!isAlpha(s[i])){
                    flag = 0;
                    cnt = 0;
                    if(tmp.size() <= 2)continue;
                    int ans = trans(tmp.substr(2));
                    mp[tmp] = ans;
                    v.push_back(tmp);
                    tmp = "";
                    continue;
                }
                tmp += s[i];
                cnt++;
            }else if(flag && cnt >= 8){
                flag = 0;
                int ans = trans(tmp.substr(2));
                mp[tmp] = ans;
                v.push_back(tmp);
                tmp = "";
            }
        }
        if(flag && cnt > 0){
            int ans = trans(tmp.substr(2));
            mp[tmp] = ans;
        }
    }
    for(auto i : v)cout << i << ' ' << mp[i] << '\n';
}