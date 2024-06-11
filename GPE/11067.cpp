#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    while(cin >> n){
        int empty = 0,ans = 0;
        ans+=n;
        empty = n;
        while(empty){
            if(empty == 2){
                empty = 0;
                ans++;
            }else if(empty <= 1){
                empty = 0;
            }else{
                ans += empty/3;
                empty= empty/3+empty%3;
            }
        }
        cout << ans << '\n';
    }

}