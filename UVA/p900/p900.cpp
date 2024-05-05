//uva900
#include<bits/stdc++.h>
using namespace std;

signed main(){
    int a[55] = {0};
    a[1] = 1,a[2] = 2;
    for(int i = 3; i <= 50; i++)a[i] = a[i-2]+a[i-1];
    int t;
    while(cin >> t,t){
        cout << a[t] << '\n';
    }
}