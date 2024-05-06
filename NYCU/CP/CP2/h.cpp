//Multigram
#include<bits/stdc++.h>
using namespace std;

signed main(){
    string s;
    cin >> s;
    int ans = -1;
    int n = s.size();
    int cnt1[30],cnt2[30];

    for(int len = n-1; len >= 1; len--){
        if(n%len)continue;
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        for(int i = 0; i < len; i++){
            cnt1[s[i]-'a']++;
        }
        bool ok = 1;
        for(int i = len; i < n; i++){
            cnt2[s[i]-'a']++;
            if(i%len == len-1){
                for(int j = 0; j < 30; j++){
                    if(cnt1[j]!=cnt2[j]){
                        ok = 0;
                    }
                }
                memset(cnt2,0,sizeof(cnt2));
            }
        }
        if(ok)ans = len;
    }
    if(ans < 0)cout << "-1";
    else{
        for(int i = 0; i < ans; i++)cout << s[i];
    }
}