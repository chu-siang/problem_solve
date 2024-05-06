//Delimiter Soup
#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int MAXN = 1e4+5;
ld c[105];
ld d[105];

char tran(char c){
    if(c == ')')return '(';
    if(c == ']')return '[';
    if(c == '}')return '{';
    return c;
}
signed main(){
    int t;
    cin >> t;
    cin.ignore();
    string s;
    getline(cin,s);
    int n = s.size();
    stack<char>st;
    for(int i = 0; i < n; i++){
        if(s[i] == ' ')continue;
        else if(s[i] == tran(s[i])){
            st.push(s[i]);
        }else if(st.size() && st.top() == tran(s[i])){
            st.pop();
        }else{
            cout << s[i] << ' ' << i;
            return 0;
        }
    }
    cout << "ok so far";

}