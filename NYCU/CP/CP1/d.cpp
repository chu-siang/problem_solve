//Parsing hex
#include<bits/stdc++.h>
#define int long long
using namespace std;

int tran(char c){
    if(c == 'a'){
        return 10;
    }else if(c == 'b'){
        return 11;
    }else if(c == 'c'){
        return 12;
    }else if(c == 'd'){
        return 13;
    }else if(c == 'e'){
        return 14;
    }else if(c == 'f'){
        return 15;
    }
    return (c-'0');
}

int cal(string s){
    int tmp = 0;
    for(int i = 2; i < s.size(); i++){
        tmp *= 16;
        tmp += (tran(tolower(s[i])));
    }
    return tmp;
}

signed main(){
    string s;
    while(getline(cin, s)){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0' && tolower(s[i+1]) == 'x'){
                string tmp = "";
                tmp += s[i];
                tmp +=s[i+1];
                i+=2;
                while(i < s.size() &&(tmp.size() <= 10) && (('a' <= tolower(s[i]) && tolower(s[i]) <= 'f') 
                    || ('0'<= s[i]  && s[i] <= '9'))){
                    tmp += s[i];
                    i++;
                }
                if(tmp.size() > 2)cout << tmp << ' ' << cal(tmp) << '\n';
            }
        }
    }
}