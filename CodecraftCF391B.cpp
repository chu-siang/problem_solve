#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> t;
    map<int,int>mp;
    while(t--){
        cin >> n;
        for(int i = 2; i * i <= n; i++){
            if(n%i!=0) continue;;
            mp[i]++;
            while(n % i == 0) n /= i;
        }
        if(n != 1) mp[n]++;
    }
     int ans = 1; 
    for(auto ai: mp) ans = max(ans , ai.second);
    cout << ans << '\n';
}