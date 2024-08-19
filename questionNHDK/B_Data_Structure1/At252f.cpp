#include<iostream>
#include<queue>
#define MAXN 200005
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N,L;
    cin >> N >> L;
    
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for(ll i = 0; i < N; i++){
        ll x;
        cin >> x;
        pq.emplace(x);
        L -= x;
    }

    if(L > 0)pq.emplace(L);

    ll ans = 0;
    while(pq.size() >= 2){
        ll tmp = 0;
        tmp += pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        ans += tmp;
        pq.emplace(tmp);
    }
    cout << ans << '\n';
    return 0;
}