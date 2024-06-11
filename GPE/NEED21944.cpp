#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    while(cin >> n,n){
        for(int i = 1;; i++){
            int kill = 0;
            for(int j = 2; j < n; j++){
                kill = (kill + i)%j;
            }
            if(kill == 11){
                cout << i << '\n';
                break;
            }
        }
    }
}