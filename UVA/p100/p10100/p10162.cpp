//uva10162 LastDigit
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[105] = {0};
signed main(){
    int ans = 0;
    for(int i = 1; i < 100; i++){
        int k = i;
        for(int j = 1; j < i; j++){
            k=k*i%10;
        }
        ans = (ans+k)%10;
        a[i] = ans%10;
    }
    string s;
    while(cin >> s&& s!="0"){
        int n;
        if(s.size() > 1){
            n = 10*(s[s.size()-2]-'0')+(s[s.size()-1]-'0');
        }else{
            n = (s[0]-'0');
        }
        cout << a[n] << '\n';
    }
}