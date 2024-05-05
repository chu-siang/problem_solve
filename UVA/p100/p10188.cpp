#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,m;
    int K = 0;
    while((cin >> n).ignore(),n){
        string a,b;
        string s;
        for(int i = 0; i < n; i++){
            getline(cin,s);
            a+=s;
            if(i)a+='\n';
        }
        (cin >> m).ignore();
        for(int i = 0; i < m; i++){
            getline(cin,s);
            b+=s;
            if(i)b+='\n';
        }
        string pr1,pr2;
        for(auto i : a)if(isdigit(i))pr1+=i;
        for(auto i : b)if(isdigit(i))pr2+=i;
        cout << "Run #" << ++K << ": ";
        if(a == b)cout << "Accepted\n";
        else if(pr1 == pr2)cout << "Presentation Error\n";
        else cout << "Wrong Answer\n";
    }
}
