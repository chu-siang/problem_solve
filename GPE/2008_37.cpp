#include<bits/stdc++.h>
using namespace std;


signed main(){
    string s;
    while(getline(cin,s)){
        if(s[0] == '.')break;
        stringstream ss(s);
        stack<int>st;
        stack<char>op;
        bool ok = false;
        int t = 0;
        while(ss >> s){
            int l = s.size();
            if(l == 1){
                if(isdigit(s[0]))st.push(s[0]-'0'),t = (t?2:1);
                else op.push(s[0]),t = 0;
            }else{
                int n = 0;
                for(int i = 0; i < l; i++){
                    n = n*10+(s[i]-'0');
                }
                st.push(n);
                if(!t)t = 1;
                else t = 2;
            }
            while(st.size() > 1 && t == 2){
                if(op.size()){
                    char c = op.top();
                    op.pop();
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    if(c == '+'){
                        st.push(a+b);
                    }else if(c == '-'){
                        st.push(b-a);
                    }else if(c == '*'){
                        st.push(a*b);
                    }else if(c == '/'){
                        st.push(b/a);
                    }else if(c == '%'){
                        st.push(b%a);
                    }
                }else{
                    ok = true;
                    break;
                }
            }
            if(ok)break;
        }
        while(st.size() > 1 &&op.size()){
            char c = op.top();
            op.pop();
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(c == '+'){
                st.push(a+b);
            }else if(c == '-'){
                st.push(b-a);
            }else if(c == '*'){
                st.push(a*b);
            }else if(c == '/'){
                st.push(b/a);
            }else if(c == '%'){
                st.push(b%a);
            }
        }
        if(op.size() || st.size() > 1)ok = true;
        if(ok)cout << "illegal\n";
        else cout << st.top() << '\n';
        ss.clear();
        ss.str("");
        
    }
}