#include<bits/stdc++.h>
using namespace std;

char ch(char c){
    if(c == ')')return '(';
    if(c == ']')return '[';
    if(c == '}')return '{';
    return c;
}

signed main(){
    string s;
    cin >> s;
    stack<char>st;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(st.empty())st.push(s[i]);
        else if(s[i] == ch(s[i])){
            st.push(s[i]);
        }else if(st.top() == ch(s[i])){
            st.pop();
        }else{
            ans++;
        }
    }
    ans += (int)st.size();
    cout << ans << '\n';
}