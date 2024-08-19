#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    priority_queue<int,vector<int>,greater<int>>pq;
    while(n--){
        int tmp;
        cin >> tmp;
        sum += tmp;
        pq.emplace(tmp);
        while(sum < 0){
            tmp = pq.top();
            sum -= tmp;
            pq.pop();
        }
    }
    cout << pq.size();
}