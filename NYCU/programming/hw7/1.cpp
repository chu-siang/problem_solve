//a080 uva 458
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        int l = s.length();
        for(int i = 0; i < l; i++){
            cout << (char)(s[i]-7);
        }
        cout << '\n';
    }
}