#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin >> t;
    string a[3] = {"one","two","three"};
    while(t--){
        string s;
        cin >> s;
        int l = s.length();
        int ans;
        if(l == 3){
            for(int i = 0; i < 2; i++){
                ll cnt = 0;
                for(int j = 0; j < 3; j++){
                    if(s[j] != a[i][j])cnt++;
                }
                if(cnt <= 1)ans = i+1;
            }
        }else ans = 3;
        cout << ans << '\n';
    }
}