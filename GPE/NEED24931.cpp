//uva 11475
#include<bits/stdc++.h>
using namespace std;

signed main(){
    string s;
    while(cin >> s){
        cout << s;
        int next[s.size()] = {},i = 1, j = 0;
        string t = s;
        reverse(t.begin(),t.end());
        while(i < t.size()){
            if(t[i] == t[j])next[i++] = ++j;
            else if(!j)i++;
            else j = next[j-1];
        }
        i = 0,j = 0;
        while(i < s.size()){
            if(s[i] == t[j])i++,j++;
            else if(!j)i++;
            else j = next[j-1];
        }
        cout << t.substr(j,t.size()-j) << '\n';
    }
}