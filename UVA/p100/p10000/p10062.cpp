#include <bits/stdc++.h>
#define ppp pair<int,int>
using namespace std;

bool cmp(ppp a,ppp b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second > b.second;
}

int main(){
    string s;
    bool flag = false;
    while(getline(cin,s)){
        if(flag) cout << "\n";
        ppp p[261];
        for(int i = 0; i < 256 ;i++){
            p[i] = {0,i};
        }
        for(int i = 0; i<s.size();i++){
            p[(int)s[i]].first++;
        }
        sort(p,p+256,cmp);
        for(auto a:p) {
            if(a.first > 0){
                cout <<a.second << " " << a.first << '\n';
            }
        }
        flag = true;
    }
}