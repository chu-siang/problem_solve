#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s;
    bool flag;
    while(getline(cin,s)){
        int l = s.length();
        string ans ="";
        for(int i = 0; i < l; i++){
            if(s[i] == '\"'){
                if(!flag){
                    ans += "``";
                    flag = !flag;
                }else{
                    ans += "\'\'";
                    flag = !flag;
                }
            }else{
                ans += s[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}