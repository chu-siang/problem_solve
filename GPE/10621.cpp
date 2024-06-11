#include<bits/stdc++.h>
using namespace std;

int dp[200];

signed main(){
    int n;
    cin >> n;
    int sum = 0;
    cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        int x;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        sum = 0;
        while(ss >> x){
            for(int i = 200; i >= x; i--){
                if(dp[i-x]){
                    dp[i] = true;
                }
            }
            sum += x;
        }
        cout << (sum%2 == 0 && dp[sum/2] ? "YES\n" : "NO\n");
    }

}