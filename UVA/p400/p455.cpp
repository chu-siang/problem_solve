#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(string str,string s,int n){
    int l = s.length();
    for(int i = 0; i < l; i+=n){
        if(s.substr(i,n)!=str)return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,k;
    cin >> n;
    string s;
    getline(cin,s);
    while(n--){
        getline(cin,s);
        getline(cin,s);
        int len = s.length();
        for(int i = 1; i <= len; i++){
            if(len % i != 0) continue;
            string str = s.substr(0,i);
            if(cmp(str,s,i)){
                cout << i << '\n';
                break;
            }
        }
        if(n)cout << '\n';
    }
}