#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e4+5;
int pr[MAXN],sum[MAXN],ans[MAXN] = {0};
bool visit[MAXN] = {0};
int num = 0;
void prime(){
    for(int i = 2; i < MAXN; i++){
        if(!visit[i]){
            pr[++num] = i;
            sum[num] = pr[num] + sum[num-1];
        }
        for(int j = i*2; j <= 1e4 ; j+=i){
            visit[j] = 1;
        }
    }
    for(int i = 1; i <= num; i++){
        for(int j = i; j <= num; j++){
            int x = sum[j]-sum[i-1];
            if(x < 1e4)ans[x]++;
        }
    }
}

signed main(){
    int n;
    prime();
    while(cin >> n,n){
        cout << ans[n] << '\n';
    }
}