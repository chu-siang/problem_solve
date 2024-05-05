//uva 10036
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e3+5;
bool visit[MAXN][MAXN];
string s[MAXN];
int h,w;
void dfs(int x,int y,char c){
    if(x < 0 || y < 0 || x >= h || y >= w)return;
    if(visit[x][y] || s[x][y] != c)return;
    visit[x][y] = 1;
    dfs(x+1,y,c);
    dfs(x,y+1,c);
    dfs(x-1,y,c);
    dfs(x,y-1,c);
}
struct CMP{
    bool operator () (pair<char,int>a, pair<char,int>b){
        if(a.second == b.second)return a.first < b.first;
        return a.second > b.second;
    }
};

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    int cnt = 0;
    cin >> n;
    while(n--){
        cin >> h >> w;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                visit[i][j] = 0;
            }
        }
        map<char,int>mp;
        for(int i = 0; i < h; i++)cin >> s[i];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(visit[i][j])continue;
                mp[s[i][j]]++;
                dfs(i,j,s[i][j]);
            }
        }
        cout << "World #" << ++cnt << '\n';
        set<pair<char,int>,CMP>st;
        for(auto i:mp){
            st.emplace(make_pair(i.first,i.second));
        }
        for(auto i : st){
            cout << i.first << ": " << i.second << '\n';
        }
    }
}