#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,d;
    while(cin >> n >> d){
        int i = n;
        for(; i < d; i+=n){
            n++;
        }
        cout << n << '\n';
    }
}