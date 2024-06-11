//uva 10258
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct People{
    map<int,int>mp;
    bool visit = false;
    bool pb[15] = {0};
    int cnt = 0;
    int num = 0;
    int penalty = 0;
};
bool cmp(People x,People y){
    if(x.cnt == y.cnt){
        if(x.penalty == y.penalty){
            return x.num < y.num;
        }
        return x.penalty < y.penalty;
    }
    return x.cnt > y.cnt;
}

signed main(){
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--){
        People p[105];
        string s;
        while(getline(cin,s)){
            if(s == "")break;
            stringstream ss(s);
            int a,b,c;
            char ca;
            ss >> a >> b  >> c >> ca;
            ss.clear();
            ss.str("");
            if(ca == 'R' || ca == 'U' || ca == 'E'){
                p[a].visit = 1;
                p[a].num = a;
                continue;
            }
            if(ca == 'C'){
                if(p[a].pb[b])continue;
                p[a].pb[b] = 1;
                p[a].cnt++;
                p[a].penalty+=(c+(20*p[a].mp[b]));
                p[a].num = a;
                p[a].visit = true;
            }else{
                if(p[a].pb[b])continue;
                p[a].mp[b]++;
                p[a].visit = true;
                p[a].num = a;
            }
        }
        sort(p,p+105,cmp);
        bool flag = false;
        for(auto i : p){
            if(i.visit){
                cout << i.num << ' ' << i.cnt << ' ' << i.penalty << '\n';
            }
        }
        if(t)cout << "\n";
    }
}
/*
1

1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C
*/