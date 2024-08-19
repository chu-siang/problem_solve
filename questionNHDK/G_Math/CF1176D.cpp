#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 3e6+5;
int pos[MAXN] = {0};
int rprime[MAXN],prime[MAXN],a[MAXN],cn[MAXN];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    int mx = 3e6,cnt = 0;
    for(int i = 2; i <= mx; i++){
        if(!pos[i]){
            prime[++cnt] = i;
        }
        for(int j = 1; j <= cnt; j++){
            if(prime[j] * i > mx)break;
            pos[prime[j] * i] = prime[j];
            if(i % prime[j] == 0)break;
        }
    }
    cin >> n;
    int num;
    for(int i = 1; i <= cnt; i++)rprime[prime[i]] = i;
    for(int i = 1; i <= 2*n; i++){
        cin >> a[i];
        cn[a[i]]++;
    }
    for(int i = mx; i >= 1; i--){
        while(cn[i]){
            if(!pos[i]){
                cout << rprime[i] << ' ';
                cn[rprime[i]]--;
            }else{
                cout << i << ' ';
                cn[i/pos[i]]--;
            }
            cn[i]--;
        }
    }
    return 0;
}   