#include<bits/stdc++.h>
#define int long long
using namespace std;

int b[27];
vector<int>G[27];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1;
    bool flag = false;
    for(int i = 2; i <= n; i++){
        cin >> s2;
        int len = min(s1.length(),s2.length());
        for(int j = 0; j <= len; j++){
            if(j == len){
                if(s1.length() > s2.length()){
                    cout << "Impossible";
                    return 0;
                }
                break;
            }
            if(s1[j] != s2[j]){
                G[s1[j]-'a'].push_back(s2[j]-'a');
                b[s2[j]-'a']++;
                break;
            }
        }
        s1 = s2;
    }
    queue<int>q;
    for(int i = 0; i < 26; i++){
        if(!b[i])q.push(i);
    }
    vector<char>topo;
    while(q.size()){
        int now = q.front();
        topo.push_back((char)('a'+now));
        q.pop();
        for(int e : G[now]){
            b[e]--;
            if(!b[e])q.push(e);
        }
    }
    if(topo.size()!=26){
        cout << "Impossible";
        return 0;
    }
    for(auto i : topo)cout << i;
}
