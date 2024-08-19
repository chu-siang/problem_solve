#include<bits/stdc++.h>
#define ll long long
#define MAXN 1005
using namespace std;
//pair<int,int> p = make_pair<int,int>


int main(){
    ll n,m;
    cin >> n;
    vector<string> v(n);
    ll l = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i].length() > l) l = v[i].length();
    }
    string ans = "";
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++){
            if(i < v[j].length() && isupper((char)v[j][i])) ans = ans + v[j][i];
        }
    }
    cout<< ans;
    return 0;
}