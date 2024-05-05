#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool prime(ll n){
    if(n == 2 || n == 1)return true;
    if(!(n&1))return false;
    for(int i = 3; i * i <= n; i+=2){
        if(n % i == 0)return false;
    }
    return true;
}
int main(){

    string s;
    while(cin >> s){
        ll sum = 0;
        int l = s.length();
        for(int i = 0; i < l; i++){
            if(s[i] >= 'a' && s[i] <= 'z')sum += s[i]-'a'+1;
            else sum += s[i] - 'A' + 27;
        }
        if(prime(sum))cout << "It is a prime word.\n";
        else cout << "It is not a prime word.\n";
    }
}