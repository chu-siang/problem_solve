#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    while(getline(cin,s)){
        ll cnt = 0;
        int l = s.length();
        bool a = false;
        //aaa.  a...  a.a.
        for(int i = 0; i < l; i++){
            if(isalpha(s[i]))a = true;
            else{
                if(a){
                    cnt++;
                    a = false;
                }
            }
        }
        if(a)cnt++;
        cout << cnt << '\n';
    }
}