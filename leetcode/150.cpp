class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        auto ac = [&](char c,int a,int b){
            if(c == '+')return a+b;
            if(c == '-')return a-b;
            if(c == '*')return a*b;
            if(c == '/')return a/b;
            return 0;
        };
        for(string s : tokens){
            if(s == "+" || s == "-" || s == "/" || s == "*"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(ac(s[0],a,b));
            }else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};