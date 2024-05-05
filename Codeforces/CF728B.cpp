#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,int> mp;
        for(int i = 1; i <= n; i++){
            int x;
            cin >>x;
            mp[x] = i;
        }
        ll ans = 0;
        for(auto &[a,i] : mp){
            for(int b = 1; a * b <= 2 * n -1; b++){
                if(a == b) continue;
                if(mp.count(b) && mp[b] + i == a * b) ans++ ;
            }
        }
        cout << ans/2 << '\n';
    }
}