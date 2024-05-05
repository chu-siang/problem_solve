#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    
    while(cin >> t,t){
        string s;
        map<string,int>mp;
        mp["top"] = 1;
        mp["west"] = 3;
        mp["north"] = 2;
        mp["east"] = 4;
        mp["south"] = 5;
        mp["under"] = 6;
        while(t--){
            cin >> s;
            if(s == "north"){
                int tmp = mp["top"];
                mp["top"] = mp["south"];
                mp["south"] = mp["under"];
                mp["under"] = mp["north"];
                mp["north"] = tmp;
            }else if(s == "east"){
                int tmp = mp["top"];
                mp["top"] = mp["west"];
                mp["west"] = mp["under"];
                mp["under"] = mp["east"];
                mp["east"] = tmp;
            }else if(s == "west"){
                int tmp = mp["top"];
                mp["top"] = mp["east"];
                mp["east"] = mp["under"];
                mp["under"] = mp["west"];
                mp["west"] = tmp;
            }else if(s == "south"){
                int tmp = mp["top"];
                mp["top"] = mp["north"];
                mp["north"] = mp["under"];
                mp["under"] = mp["south"];
                mp["south"] = tmp;
            }
        }
        cout << mp["top"] << '\n';
    }
    
    return 0;
}

