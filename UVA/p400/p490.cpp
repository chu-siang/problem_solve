#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s[105],s2[105];
    int n = 0,mx = 0;
    while(getline(cin,s[n])){
        int len = s[n].length();
        if(len > mx)mx = len;
        n++;
    }
    for(int i = 0; i < mx; i++){
        for(int j = 0; j < n; j++){
            if(i >= s[j].length()) s2[i] = " " + s2[i];
            else {
                s2[i] = s[j][i] + s2[i];
            }
        }
        cout << s2[i] << '\n';
    }

    return 0;
}