//Canvas Painting
#include<bits/stdc++.h>
#define int long long
using namespace std;

singed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int num;
        int sum =  0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i =0 ; i < n; i++){
            cin >> num;
            pq.push(num);
        }
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            sum += a+b;
            pq.push(a+b);
        }
        cout << ans << '\n';
    }
}