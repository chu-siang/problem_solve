//POJ1760
//uva 1556
#include<bits/stdc++.h>
#define int long long
using namespace std;
int sz;
const int MAXN = 4e5+5;
struct Node{
    map<string,int>vis;
    string name;
}node[MAXN];


void insert(string s){
    int len = s.size();
    s += '\\';
    int u = 0;
    for(int i = 0; i <= len; i++){
        string tmp = "";
        while(s[i]!= '\\'){
            tmp += s[i];
            i++;
        }
        if(!node[u].vis.count(tmp)){
            node[sz].vis.clear();
            node[sz].name = tmp;
            node[u].vis[tmp] = sz;
            sz++;
        }
        u = node[u].vis[tmp];
    }
}

void print(int u,int d){
    if(u){
        for(int i = 0; i < d; i++)cout << ' ';
        cout << node[u].name << '\n';
    }
    for(auto i : node[u].vis){
        print(i.second,d+1);
    }
}

signed main(){
    int n;
    while(cin >> n){
        sz = 1;
        string s;
        node[0].vis.clear();
        for(int i = 0; i < n; i++){
            cin >> s;
            insert(s);
        }
        print(0,-1);
        cout << '\n';
    }
}