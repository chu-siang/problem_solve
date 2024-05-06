#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        int num;
        int count = 0;
        int a = 0;
        string s = "",s1;
        getline(cin,s1);
        int l = s1.length();
        for(int i = 0; i < l; i++){
            if(s1[i] == ' ')continue;
            else s += s1[i];
        }
        for(int i = 0; i < 16; i+=2){
            num =(s[i]-'0')*2;
            while(num){
                count += (num%10);
                num/=10;
            }
        }
        for(int i = 1; i < 16; i+=2){
            num =(s[i]-'0');
            while(num){
                count += (num%10);
                num/=10;
            }
        }
        if(count%10 == 0)cout << "Valid\n";
        else cout << "Invalid\n";
    }
}