#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    map<string,int>mp;
    while(cin >> n,n){
        mp["top"] = 1;
        mp["buttom"] = 6;
        mp["north"] = 2;
        mp["west"] = 3;
        mp["east"] = 4;
        mp["south"] = 5;
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            if(s == "north"){
                int tmp = mp["north"];
                mp["north"] = mp["top"];
                mp["top"] = mp["south"];
                mp["south"] = mp["buttom"];
                mp["buttom"] = tmp;
            }else if(s == "south"){
                int tmp = mp["south"];
                mp["south"] = mp["top"];
                mp["top"] = mp["north"];
                mp["north"] = mp["buttom"];
                mp["buttom"] = tmp;
            }else if(s == "west"){
                int tmp = mp["west"];
                mp["west"] = mp["top"];
                mp["top"] = mp["east"];
                mp["east"] = mp["buttom"];
                mp["buttom"] = tmp;
            }else if(s == "east"){
                int tmp = mp["east"];
                mp["east"] = mp["top"];
                mp["top"] = mp["west"];
                mp["west"] = mp["buttom"];
                mp["buttom"] = tmp;
            }
        }
        cout << mp["top"] << '\n';
    }
}