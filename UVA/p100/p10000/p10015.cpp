#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+5;


bool visit[MAXN];
vector<int>primes;

signed main(){
    int n;
    memset(visit,0,sizeof(visit));
    for(int i = 2; i <= 100000; i++){
        if(!visit[i]){
            primes.push_back(i);
        }
        for(auto j:primes){
            if(j*i >= 1e5)break;
            visit[j*i] = 1;
        }
    }
    while(cin >> n,n){
        int ans = 0;
        for(int i = 2; i <= n; i++){
            ans = (ans+primes[n-i])%i;
        }
        cout << ans+1 << '\n';
    }

}