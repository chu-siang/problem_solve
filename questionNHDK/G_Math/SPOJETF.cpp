#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e7;
bool prime[MAXN];
vector<int>PR;
vector<int>lpf(MAXN);

signed main(){
    memset(prime,1,MAXN);
    for(int i = 2; i <= MAXN; i++){
        if(prime[i]){
            PR.push_back(i);
            lpf[i] = i;
        }
        for(auto j : PR){
            if(j * i > MAXN)break;
            prime[j * i] = false;
            lpf[i*j] = j;
            if(i % j == 0)break;
        }
    }
    lpf[1] = 2LL;
    int n;
    cin >> n;
    prime[1] = 0;
    while(n--){
        int x;
        cin >> x;
        if(x == 0)return 0;
        if(prime[x])cout << x-1 << '\n';
        else{
            int ans = x;
            while(x % lpf[x] == 0){
                int t = lpf[x];
                while(x % t == 0){
                    x/=t;
                }
                ans = ans - ans/t;
            }
            if(x > 1)ans-=ans/x;
            cout << ans << '\n';
        }
    }
    return 0;
}