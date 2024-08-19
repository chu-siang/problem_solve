#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    int n,k;
    while(t--){
        cin >> n >> k;
        int x;
        int ans = 1,sum = 1,s = 0;
        map<int,int>mp;
        for(int i = 0; i < n; i++){
            sum = 1;
            cin >> x;
            for(int j = 2; j * j <= x; j++){
                s = 0;
                while(x % j == 0){
                    x/=j;
                    s++;
                }
                if(s&1)sum *= j;
            }
            if(x > 1)sum*=x;
            if(mp[sum]){
                ans++;
                mp.clear();
                
            }
            mp[sum] = 1;
        }
        cout << ans << '\n';
    }
    

    return 0;
}   