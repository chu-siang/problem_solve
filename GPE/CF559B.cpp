#include<bits/stdc++.h>
using namespace std;

string mer(string a){
    if(a.size()&1)return a;
    string s1 = mer(a.substr(0,a.size()/2));
    string s2 = mer(a.substr(a.size()/2));
    
    return ((s1 > s2)?s1+s2:s2+s1);
}

signed main(){
    string a,b;
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin >> a >> b){
        if(mer(a) == mer(b)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}