#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    int arr[27] = {0};
    char c;
    for(int i = 0; i < t; ++i){
        cin >> c;
        if(c == 'T')arr[i] = 1;
    }
    stack<int>ans;
    cin.ignore();
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(ss >> c){
        if(c == '*'|| c == '+'){
            int a = ans.top();
            ans.pop();
            int b = ans.top();
            ans.pop();
            if(c == '*'){
                ans.push(a&b);
            }else{
                ans.push(a|b);
            }
        }else if(c == '-'){
            int a = ans.top();
            ans.pop();
            ans.push(!a);
        }else if(c !=' '){
            ans.push(arr[c-'A']);
        }
    }
    if(ans.top())cout << "T\n";
    else cout << "F\n";
}