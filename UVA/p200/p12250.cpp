#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    string s;
    int i = 0;
    map<string,string> m;
    m["HOLA"] = "SPANISH";
    m["HELLO"] = "ENGLISH";
    m["HALLO"] = "GERMAN";
    m["BONJOUR"] = "FRENCH";
    m["CIAO"] = "ITALIAN";
    m["ZDRAVSTVUJTE"] = "RUSSIAN";
    while(cin >> s){
        if(s == "#")break;
        cout <<"Case "<< ++i << ": ";
        auto it = m.find(s);
        if(it != m.end())cout << m[s] << '\n';
        else cout << "UNKNOWN\n";
    }
}
