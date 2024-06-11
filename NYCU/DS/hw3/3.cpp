#include<bits/stdc++.h>
using namespace std;


signed main(){
    string s;
    cin >> s;
    string ans = "";
    stack<string>num;
    int l = s.size();
    string stmp = "";
    string itmp = "";
    string tmp = "";
    stack<string>data;
    for(int i = 0; i < l; i++){
        if(s[i] == '['){
            if(stmp != ""){
                data.push(stmp);
                stmp = "";
            }else data.push("[");
            num.push(itmp);
            itmp = "";
        }else if(s[i] == ']'){
            string a = stmp;
            stmp = "";
            string b = num.top();
            num.pop();
            int t = stoi(b);
            for(int j = 0; j < t; j++){
                stmp = a + stmp;
            }
            if(data.top() != "[")stmp = data.top() + stmp;
            data.pop();
            if(num.empty()){
                ans += stmp;
                stmp = "";
            }
        }else if(isalpha(s[i])){
            stmp += s[i];
        }else{
            itmp += s[i];
        }
    }
    cout << ans+"\n";
}