//Euler's Number
#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin >> n;
    double ans = 0;
    double tt = 1;
    for(int i = 1; i <= n; i++){
        tt *= i;
        ans += (1/tt); 
    }
    printf("%0.15lf", ans+1);
}