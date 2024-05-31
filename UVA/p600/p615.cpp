//uva615 disjoint_set solution
#include <bits/stdc++.h>
using namespace std;

map<int,int>mp;
map<int,int>used;
int root_set(int a){
    if(a!=mp[a]){
        mp[a] = root_set(mp[a]);
    }
    return mp[a];
}

signed main(){
    int x,y;
    bool flag = true;
    while(cin >> x >> y){
        if(x == 0 && y == 0)break;
        if(!mp[x])mp[x]=x;
        if(!mp[y])mp[y]=y;
        if(root_set(x) == root_set(y)){
            flag = 0;
        }else{
            used[x] = used[y] = 1;
            mp[root_set(y)] = root_set(x);
        }
    }
    if(flag){
        int cnt = 0;
        for(auto i:used){
            if(i.second == root_set(i.second)){
                if(cnt++){
                    flag = 0;
                    break;
                }
            }
        }
    }
    if(flag)cout << "True\n";
    else cout << "False\n";
}
