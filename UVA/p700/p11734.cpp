#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int t;
    cin >> t;
    string s;
    getline(cin,s);
    for(int c = 1; c <= t; c++){
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        cout << "Case " << c <<": ";
        if(s2 == s1)cout << "Yes\n";
        else{
            string s3,s4;
            ll l1 = s1.length(), l2 = s2.length();
            for(ll i = 0; i < l1; i++)if(s1[i]!= ' ')s3+=s1[i];
            for(ll i = 0; i < l2; i++)if(s2[i]!= ' ')s4+=s2[i];
            if(s3 == s4)cout << "Output Format Error\n";
            else cout << "Wrong Answer\n";
        }
    }
}
/*
3 
yes
yes
Casematters
casematters
no space     please
nospaceplease
*/