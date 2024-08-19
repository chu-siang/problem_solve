#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    bool flag = false;
    for(int i = 2; i * i <= n; i++){
        int cnt = 0;
        while(n % i == 0){
            cnt++;
            n/=i;
        }
        if(cnt > 1){
            if(flag) cout << " * ";
            flag = true;
            cout << i << "^" << cnt;
        }else if (cnt){
            if(flag)cout << " * ";
            flag = true;
            cout << i;
        }
    }
    if(n > 1){
        if(flag)cout << " * ";
        cout << n;
    }
}