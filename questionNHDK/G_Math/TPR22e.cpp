#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e6+5;
const int mx = 2e6+4;
int arr[MAXN],lpf[MAXN],pre[MAXN];
bool prime[MAXN];
vector<int>primes;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fill(prime+2,prime+mx,true);
    for(int i = 2; i < mx; i++){
        if(prime[i]){
            primes.push_back(i);
            lpf[i] = i;
        }
        for(auto p : primes){
            if(i*p > mx)break;
            prime[i*p] = false;
            lpf[i*p] = p;
            if(i % p == 0)break;
        }
    }
    int n,q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> arr[i];
    pre[0] = 0;
    lpf[1] = 2;
    for(int i = 0; i < n; i++){
        int x = arr[i];
        map<int,int>mp;
        mp.clear();
        while(x != 1){
            if(x % lpf[x] == 0){
                mp[lpf[x]]++;
                x/=lpf[x];
            }
        }
        int sum = 0;
        for(auto t:mp){
            sum += t.first*t.second;
        }
        pre[i+1] = pre[i] + sum;
    }
    int a,b;
    while(q--){
        cin >> a >> b;
        cout << pre[b]-pre[a-1] << '\n';
    }
}
