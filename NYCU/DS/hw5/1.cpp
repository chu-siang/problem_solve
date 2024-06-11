//uva459
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int>v[26];
bool vis[26] = {0};
void dfs(int top){
    for(int i : v[top]){
        if(!vis[i]){
            vis[i] = 1;
            dfs(i);
        }
    }
}
signed main(){
    int n;
    char c,a,b;
    cin >> c;
    memset(vis,0,sizeof(vis));
    n = c - 'A';
    string s;
    getline(cin,s);
    while(cin >> s){
        if(s == "\n")break;
        v[s[0]-'A'].push_back(s[1]-'A');
        v[s[1]-'A'].push_back(s[0]-'A');
    }
    int now = 0;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            ans++;
            dfs(i);
        }
    }   
    cout << ans << '\n';
    
}