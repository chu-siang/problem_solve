//uva 10110
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    while(cin >> n,n){
        int t = (int)(sqrt((double)n));
        if(t*t == n){
            cout << "yes\n";
        }else cout << "no\n";
    }
}