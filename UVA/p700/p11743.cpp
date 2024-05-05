#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long as = 0, bs =0;
        string s;
        int n = 4;
        while(n--){
            cin >> s;
            for(int i = 0; i < 4; i++){
                if((i+1)&1){
                    int a = s[i] -'0';
                    a *= 2;
                    while(a !=0){
                        as += a%10;
                        a/=10;
                    }
                }else{
                    as += s[i]-'0';
                }
            }
        }
        if(as % 10 == 0)cout << "Invalid" << '\n';
        else cout << "Valid" << '\n';
    }
}