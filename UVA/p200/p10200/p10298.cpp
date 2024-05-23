#include<bits/stdc++.h>
using namespace std;

signed main(){
    string a;
    while(cin >> a){
        if(a == ".")break;
        int ans = -1;
        int n = a.size();
        for(int i = n; i >= 1; i--){
            if(n%i == 0){
                bool flag = true;
                string tmp = a.substr(0,i);
                for(int j = 0; j < n; j+=i){
                    if(tmp!=a.substr(j,i)){
                        flag = false;
                        break;
                    }
                }
                if(flag)ans = i;
            }
        }
        cout << (n/ans) << '\n';
    }
}