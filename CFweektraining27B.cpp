#include<bits/stdc++.h>
using namespace std;
const int SIZE = 5e6+10;
int m, d[30], cnt[SIZE], an;
void dfs(int i, int x, int v){
    if(i == m){
        an = min(an,v);
        return ;
    }
    int nxt = x+d[i];
    cnt[nxt]++;
    dfs(i+1, nxt, v+(cnt[nxt] == 1));
    cnt[nxt]--;

    nxt = x - d[i];
    cnt[nxt]++;
    dfs(i + 1, nxt , v+ (cnt[nxt] == 1));
    cnt[nxt]--;
}


int main(){
    scanf("%d",&m);
    an = m + 1;
    for(int i = 0; i < m; i++)
        scanf("%d",&d[i]);
    cnt[SIZE/2] = 1;
    cnt[SIZE/2 + d[0]] = 1;
    dfs(1,SIZE/2+d[0],2);
    printf("%d\n",an);
    return 0;
}