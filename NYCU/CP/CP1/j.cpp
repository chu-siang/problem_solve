//Circuit Math
#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;

signed main(){
    int n;
    cin >> n;
    map<char,bool>mp;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'T')mp[(char)'A'+i] = 1;
        else mp[(char)'A'+i] = 0;
    }
    stack<bool>st;
    while(cin >> c){
        if(c == '+'){
            bool a = st.top();
            st.pop();
            bool b = st.top();
            st.pop();
            st.push(a|b);
        }else if(c == '-'){
            bool a = st.top();
            st.pop();
            st.push(!a);
        }else if(c == '*'){
            bool a = st.top();
            st.pop();
            bool b = st.top();
            st.pop();
            st.push(a&b);
        }else{
            st.push(mp[c]);
        }
    }
    if(st.top() == 0)cout << 'F';
    else cout << "T";
}