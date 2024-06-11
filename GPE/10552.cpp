//uva 10188
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,m;
    int run = 0;
    while(cin >> n,n){
        string s;
        run++;
        string s1 = "",s2 = "";
        getline(cin,s);
        for(int i = 0; i < n; i++){
            getline(cin,s);
            s1+=s;
            if(i)s1+='\n';
        }
        cin >> m;
        getline(cin,s);
        for(int i = 0; i < m; i++){
            getline(cin,s);
            s2+=s;
            if(i)s2+='\n';
        }
        cout << "Run #"<< run << ": ";
        string n1 = "",n2 = "";
        for(char c : s1)if(isdigit(c))n1+=c;
        for(char c : s2)if(isdigit(c))n2+=c;
        if(s1 == s2)cout << "Accepted\n";
        else if(n1 == n2)cout << "Presentation Error\n";
        else cout << "Wrong Answer\n";
    }
}
