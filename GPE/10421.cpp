//uva 10193 All you need is love
#include<bits/stdc++.h>
#define int long long
using namespace std;

int BT(string s){
    int a = 0;
    for(int i = 0; i < s.size(); i++){
        a*=2;
        a+=(s[i]-'0');
    }
    return a;
}

signed main(){
    int n;
    cin >> n;
    string s1,s2;
    for(int i = 1; i <= n; i++){
        cin >> s1 >> s2;
        int a = BT(s1),b = BT(s2);
        bool flag = (__gcd(a,b) > 1);
        cout << "Pair #" << i << ": ";
        if(flag)cout << "All you need is love!\n";
        else cout << "Love is not all you need!\n"; 
    }
}