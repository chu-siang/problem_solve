//495
#include<iostream>

using namespace std;

int i = 2, j, dp[5001][2000] = {0};

int main(){
  dp[1][0] = 1;
  for(;i <= 5000;i++)
    for(j = 0;j < 2000;)
    {
        dp[i][j] += dp[i-1][j] + dp[i-2][j];
        dp[i][j+1] += dp[i][j]/10;
        dp[i][j++] %= 10;
    }

  int n, i;
    while(cin >> n){
        cout << "The Fibonacci number for "<< n <<" is " ;
        if(n == 0){
            cout << "0" << endl;
            continue;
        }
        for(i = 1999;i >= 0;i--)
            if(dp[n][i])break;
        for(;i >= 0;)
            cout << dp[n][i--];
        cout << endl;
    }   
}