#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,m, n,arr[105] = {0};
    string s;
    map<string,int>mp;
    cin >> m >> n;
    while (m--){
        cin >> s >> t;
        mp[s] = t;
    }
    while(n--){
        while(cin >> s){
            arr[m] += mp[s]; 
            if(s[0] == '.') break;
        }
        cout << arr[m++] << '\n';
    }
}