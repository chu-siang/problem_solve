#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        int ans = 1;
        for(int i = 2; i * i <= x; i++){
            int cnt = 0;
            while(x % i == 0){
                cnt++;
                x/=i;
            }
            if(cnt > 0) ans*=(cnt+1);
        }
        if(x > 1) ans *= 2;
        cout << ans << ' ';
    }
}