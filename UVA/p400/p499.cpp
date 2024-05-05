#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    while(getline(cin,s)){
        int l = s.length();
        int arr[256] = {0};
        int mx = 0;
        for(int i = 0; i < l; i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
                arr[(int)s[i]]++;
                if(arr[(int)s[i]] > mx) mx = arr[(int)s[i]];
            }
        }
        set<char>st;
        for(int i = 0; i < 256; i++){
            if(arr[i] == mx) st.emplace((char)i);
        }
        for(auto i : st) cout << i;
        cout << " " << mx << '\n';
    }
}