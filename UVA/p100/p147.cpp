#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mxn = 3e5+5;
int c[11] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
int c1[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
int dp[mxn+5];
signed main(){
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < 11; i++){
        for(int j = c[i]; j <= mxn ; j++){
            dp[j] = dp[j] + dp[j-c[i]];
        }
    }
    int d,f;
    char c;
    while(cin >> d >> c >> f){
        if(d == 0 && f == 0)break;
        cout << setw(3) << setfill(' ')<< d << '.' << setw(2) << setfill('0') 
        << f <<setw(17) << setfill(' ')<< dp[(100*d+f)] << '\n';
    }
}