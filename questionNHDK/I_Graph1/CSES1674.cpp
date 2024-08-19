#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5+5;
vector<int>G[MAXN];
int in[MAXN];
int sub[MAXN];
signed main(){
    int n;
    cin >> n;
    int a;
    for(int i = 2; i <= n; i++){
        cin >> a;
        G[i].push_back(a);
        in[a]++;
        sub[a]++;
    }
    queue<int>q;
    for(int i = 1; i <= n; i++){
        if(!in[i]){
            q.push(i);
            in[i] = INF;
        }
    }
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int e : G[now]){
            sub[e]+=sub[now];
            in[e]--;
            if(!in[e]){
                q.push(e);
                in[e] = INF;
            }
        }
    }
    for(int i = 1; i <= n; i++)cout << sub[i] << ' ';

}