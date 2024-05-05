#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    ll n;
    cin >> t;
    while(t--){
        cin >> n;
        multimap<string,string>mp;
        string s,s1;
        for(int i = 0; i < n; i++){
            cin >> s;
            s1 = s;
            sort(s1.begin(),s1.end());
            mp.insert({s1,s});
        }
        while(cin >> s){
            if(s == "END") break;
            s1 = s;
            cout << "Anagrams for: " << s << '\n';
            int i = 0;
            sort(s.begin(),s.end());
            for(auto it = mp.begin(); it != mp.end(); it++){
                if(it->first == s){
                    i++;
                    cout << "  " << i << ") " << it->second << '\n';
                }
            }
            if(i == 0) cout << "No anagrams for: " << s1 << '\n';
        }
        if(t)cout << '\n';
    }
}