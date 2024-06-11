#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int s,l;
    int cs = 0;
    int dp[27][27][352];
    dp[0][0][0] = 1;
    for(int i = 1; i <= 26; i++){
        for(int j = 0; j <= 26; j++){
            for(int k = 0; k <= 351; k++){
                if(j && k>=i)dp[i][j][k] = dp[i-1][j][k]+dp[i-1][j-1][k-i];
                else dp[i][j][k] = dp[i-1][j][k];
            }
        }
    }
    while(cin >> l >> s){
        cs++;
        if(s == 0 && l == 0)break;
        cout << "Case " << cs << ": "; 
        if(l <= 26 && s <= 351)cout << dp[26][l][s] << '\n';
        else cout << 0 << '\n';
    }
}