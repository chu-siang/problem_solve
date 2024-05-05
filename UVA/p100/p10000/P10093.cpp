#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    bool flag = false;
    while(getline(cin,s)){
        ll mx = 1;
        int l = s.length();
        int sum = 0;
        for(int i = 0; i < l; i++){
            if(s[i] <= '9' && s[i] >= '0'){
                sum += s[i]-'0';
                if(s[i] - '0' > mx) mx = s[i] - '0';
            }else if(s[i] <= 'Z' && s[i] >= 'A'){
                // Z =35
                sum += (s[i] - 'A'+10);
                if(s[i] - 'A'+10 > mx) mx = s[i] - 'A'+10;
            }else if(s[i] <= 'z' && s[i] >= 'a'){
                sum += (s[i]-'a'+36);
                if(s[i] - 'a' + 36 > mx) mx = s[i] -'a'+36;
            }else continue;
        }
        int i = mx;
        for( ; i < 62; i++){
            if((sum % i) == 0){
                cout << i + 1 << '\n';
                break;
            }
        }
        if(i == 62){
            cout << "such number is impossible!\n";
        }
    }
}
