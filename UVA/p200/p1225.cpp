#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    string s1,s2,s;
    ll t;
    map<char,int>mp;
    cin >> t;
    ll n;
    while(t--){
        cin >> n;
        for(int i = 0; i <= 9; i++){
            mp['0'+i] = 0;
        }
        for(int i = 1; i <= n; i++){
            int k = i;
            while(k){
                mp['0'+k%10]++;
                k/=10;
            }
        }
        for(int i = 0; i <= 9; i++){
            cout << mp['0'+i] << " \n"[i==9];
        }
    }

}