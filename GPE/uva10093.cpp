#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s;
    while(getline(cin,s)){
        int sum = 0;
        int mx = 1;//預設二進位 btw 有可能有負號or空白
        for(int i = 0; i < s.size(); i++){
            int tmp = 0;
            if(s[i] >= '0' && s[i] <= '9'){
                tmp = s[i]-'0';
            }else if(s[i] >= 'A' && s[i] <= 'Z'){
                tmp = s[i]-'A' + 10;
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                tmp = s[i] -'a' +36;
            }
            sum+= tmp;
            if(tmp > mx) mx = tmp;
        }
        int i = mx;
        for(; i < 62; i++){
            if(sum % i == 0){
                cout << i+1 << '\n';
                break;
            }
        }
        if(i == 62)cout << "such number is impossible!\n";
        
    }
}