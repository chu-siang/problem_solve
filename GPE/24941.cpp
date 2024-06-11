#include<bits/stdc++.h>
using namespace std;

char c;
int n = 0,t = 0;
string s = "";
vector<string>a;
void f(){
    cin.get(c);
    if(isdigit(c)){
        n = n*10+(c-'0');
        if(n == 0){
            t = 1;
            return;
        }
        f();
    }else{
        if(n)return;
        if(isalpha(c))s+=c;
        else if(s!="")a.push_back(s),s="";
        cout << c;
    }
}

signed main(){
    while(1){
        n = 0;
        f();
        if(t)break;
        if(n){
            int g = a.size();
            cout << a[a.size()-n] << c;
            string tmp = a[a.size()-n];
            a.erase(a.begin()+a.size()-n);
            a.push_back(tmp);
        }
    }
}

