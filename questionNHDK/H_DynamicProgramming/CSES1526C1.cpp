#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[2005],a[2005];

signed main(){
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>>pq;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        pq.push(num);
        cnt+=num;
        while(cnt < 0){
            int t = pq.top();
            cnt -= t;
            pq.pop();
        }
    }
    cout << pq.size();
}