#include<iostream>
#include<cmath>
#define MAXN 50005
using namespace std;
long long N, K;
long long p[MAXN];
long long rps[MAXN], lps[MAXN];

int cut(long long L, long long R, long long level){
    if(level >= K) return 0;
    if(R - L <= 1) return 0;
    lps[L] = 0;
    long long delta = 0;
    for(int i = L+1; i <= R; i++){
        delta += p[i-1];
        lps[i] = lps[i-1] + delta;
    }
    delta = 0;
    rps[R] = 0;
    for(int i = R-1; i >= L; i--){
        delta += p[i+1];
        rps[i] = rps[i+1] + delta;
    }
    long long mn = 2e18;
    long long idx = 0;
    for(int i = L+1; i <= R-1; i++){
        long long cost = abs(rps[i]-lps[i]);
        if(cost < mn){
            mn = cost;
            idx = i;
        }
    }
    return p[idx] + cut(L, idx - 1, level + 1) + cut(idx + 1, R, level + 1);
}


int main(){
    long long n;
    cin >> n >> K;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    cout << cut(1, n, 0) << '\n';
}