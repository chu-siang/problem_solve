#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(){
    string s;
    cin >> s;
    int cnt = 1;
    int tmp = 1;
    for(size_t i = 1; i < s.size(); ++i){
        while(s[i] == s[i-1] && i < s.size()){
            i++;
            tmp++;
        }
        cnt = max(tmp,cnt);
        tmp = 1;
    }
    cout << cnt;
}