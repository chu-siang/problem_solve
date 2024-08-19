#include<bits/stdc++.h>
using namespace std;

int a[260], tmp, nxt_i;
string s, str;
map<string,int>mp;
stack<int>stk;
set<string>st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    nxt_i = s.length();
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') stk.push(i);
        else if(s[i] == ')'){
            tmp = 0;
            for(int j = i+1; j < s.length(); j++){
                if(s[j] - '0' >= 0 && s[j] - '0' <= 9){
                    tmp *= 10;
                    tmp += (s[j] - '0');
                }
                else{
                    nxt_i = j - 1;
                    break;
                }
            }
            if(tmp > 1){
                for(int j = stk.top() + 1; j < i; j++){
                    a[j] *= tmp;
                }
                stk.pop();
            }
            i = nxt_i;
            nxt_i = s.length();
        }
        else if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
            tmp = 0;
            for(int j = i; j < s.length(); j++){
                if(s[j] >= '0'  && s[j]  <= '9'){
                    tmp *= 10;
                    tmp += (s[j] - '0');
                }
                else {
                    nxt_i = j - 1;
                    break;
                }
            }
            a[i - 1] *= tmp;
            i = nxt_i;
            nxt_i = s.length();
        }
        else a[i] = 1;
    }
    cout << s << '\n';
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            str = s[i];
            if(i + 1 < s.length() && s[i+1] >= 'a' && s[i+1] <= 'z'){
                str += s[i+1];
                mp[str] += max(a[i],a[i+1]);
            }
            else mp[str] += a[i];
            st.emplace(str);
        }
    }

    for(set<string> :: iterator it = st.begin(); it != st.end(); it++){
        cout << *it << ":" << mp[*it] << '\n';
    }
}