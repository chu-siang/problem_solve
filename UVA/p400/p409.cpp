#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,k;
    ll C = 0;
    while(cin >> n >> k){
        string keyword[n];
        for(int i = 0; i < n; i++){
            cin >> keyword[i];
        }
        int mx = 0;
        string excuse[k];
        string s;
        getline(cin,s);
        int cnt[20] = {0};
        for(int i = 0; i < k; i++){
            getline(cin,s);
            excuse[i] = s;
            string word = "";
            for(int j = 0; j < s.size(); j++){
                char c = tolower(s[j]);
                if(c >= 'a' && c <= 'z'){
                    word += c;
                }else{
                    for(int l = 0; l < n; l++){
                        if(word == keyword[l]){
                            cnt[i]++;
                            //break;
                        }
                    }
                    word = "";
                }
            }
            mx = max(mx,cnt[i]);
        }
        cout << "Excuse Set #" << ++C << '\n';
        for(int i = 0; i < k; i++){
            if(cnt[i] >= mx) cout << excuse[i] << "\n";
        }
        cout << '\n';
    }
}