#include<bits/stdc++.h>
using namespace std;
//要先檢查st.empty() 才能檢查top
int main(){
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        stack<char>st;
        string s="";
        getline(cin,s);
        bool flag=true;
        if(s=="" || s=="\n"){
            cout<<"Yes"<<endl;
            continue;
        }
        for(char c:s){
            if(c ==')'){
                if(st.empty()){
                    flag=false;
                    break;
                }
                if(st.top() == '('){
                    st.pop();
                }else{
                    break;
                }
            }else if(c == ']'){
                if(st.empty()){
                    flag=false;
                    break;
                }
                if(st.top() == '['){
                    st.pop();
                }else{
                    break;
                }
            }else st.push(c);
        }
        if(!flag)cout<<"No"<<endl;
        else if(!st.empty())cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}