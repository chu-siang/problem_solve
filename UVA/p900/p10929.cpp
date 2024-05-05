#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s && s != "0"){
        int sum1 = 0, sum2 = 0, l = s.length();
        for(int i = 0 ; i < l; i++){
            if(i&1)sum2 += (s[i]-'0');
            else sum1 += (s[i]-'0');
        }
        if(abs(sum1-sum2) % 11 == 0)cout << s << " is a multiple of 11." << '\n';
        else cout << s << " is not a multiple of 11."<< '\n';
    }
}