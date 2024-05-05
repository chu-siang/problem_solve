//a087  uva 11192
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    while(cin >> n,n){
        cin >> s;
        int l = s.length();
        int k = l/n;
        for(int i = 0; i < l; i+=k){
            for(int j = i + k - 1; j >= i; j--){
                cout << s[j];
            }
        }
        cout << '\n';
    }
}