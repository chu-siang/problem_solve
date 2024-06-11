#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 5e4+5;
string s[MAXN];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    unordered_set<string>st;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        st.emplace(s[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            string s1 = s[i],s2 = s[j];
            swap(s1[0],s2[0]);
            if(s1[0] == s2[0])continue;
            else if(s1.substr(1) == s2.substr(1))continue;
            else if(st.count(s1) || st.count(s2))continue;
            ans += 2;
        }
    }
    cout << ans << '\n';
}
