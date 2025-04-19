#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN];

signed main(){
    string s;
    getline(cin,s);
    stack<char>st;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '<' && (!st.empty())){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}