#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;
bool visit[MAXN];
int ans[MAXN];
int digit(int n){
    int sum = 0;
    while(n){
        sum +=n%10;
        n/=10;
    }
    return sum;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(visit,0,sizeof(visit));
    vector<int>prime;
    for(int i = 2; i < MAXN; i++){
        if(!visit[i]){
            prime.push_back(i);
        }
        for(auto t:prime){
            if(t*i > MAXN)break;
            visit[t*i] = 1;
        }
    }
    memset(ans,0,sizeof(ans));
    for(int i = 2; i < MAXN; i++){
        ans[i] = ans[i-1]+(!visit[i]&&!visit[digit(i)]);
    }
    int t;
    int a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << (ans[b]-ans[a-1]) << '\n';
    }

}