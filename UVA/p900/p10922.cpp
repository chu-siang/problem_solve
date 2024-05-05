#include <iostream>
using namespace std;

int func(string s,int count){
    int i = 0,tmp = 0, sum = 0;
    for(; i < s.length();){
        sum += (s[i++]-'0');
    }
    count++;
    if(sum == 9) return count;
    else if(sum < 9) return 0;
    else return func(to_string(sum),count);
}

int main(){
    string s,tmp;
    while(cin >> s && s!="0"){
        int  a  = func(s,0);
        if(a) cout << s << " is a multiple of 9 and has 9-degree " << a << "." << endl;
        else cout << s << " is not a multiple of 9." << endl;
    }
}