#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore();
    map<string,int>mp;
    while(n--){
        string s;
        cin >> s;
        mp[s]++;
        getline(cin,s);
    }
    for(auto i : mp) cout << i.first << ' ' << i.second << '\n';
}