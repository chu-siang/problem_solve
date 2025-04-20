#include<bits/stdc++.h>
#define int long long
using namespace std;

bool ok(char c){
    if(c == '(' || c == '[' || c == '{' || c == ' ')return true;
    return false;
}

char tran(char c){
    if(c == '(') return ')';
    if(c == '[') return ']';
    if(c == '{') return '}';

}

signed main(){
    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin,s);
    stack<char>st;
    for(int i = 0; i < s.size(); ++i){
        if(ok(s[i])){
            if(s[i] != ' ')st.push(s[i]);
        }else{
            if(st.empty()){
                cout << s[i] << ' ' << i << '\n';
                return 0;
            }
            char c = st.top();
            st.pop();
            if(tran(c) != s[i]){
                cout << s[i] << ' ' << i << '\n';
                return 0;
            }
        }
    }
    cout << "ok so far\n";
}