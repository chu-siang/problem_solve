//uva12289 a092
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string a[3] = {"one","two","threee"};
    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        int l = s.length();
        ll cnt = 0;
        ll ans = 0;
        if(l == 3){
            for(int i = 0; i < 2; i++){
                cnt = 0;
                for(int j = 0; j < 3; j++){
                    if(s[j] != a[i][j])cnt++;
                }
                if(cnt <= 1)ans = i+1;
            }
        }else ans = 3;
        cout << ans << '\n';
    }
}