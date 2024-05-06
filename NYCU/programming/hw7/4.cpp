//uva10903 a084
#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    ll n,k;
    bool flag = false;
    while(cin >> n,n){
        double w[105] = {0},l[105] = {0};
        memset(w,0,sizeof(w));
        memset(l,0,sizeof(l));
        if(flag)cout << '\n';
        flag = true;
        cin >> k;
        ll a,b;
        string s1,s2;
        k = (n-1)*(n)*k/2;
        bool flag2 = false;
        for(int i = 0; i < k; i++){
            cin >> a >> s1 >> b >> s2;
            if(s1 == "rock"){
                if(s2 == "rock"){
                    continue;
                }
                else if(s2 == "paper"){
                    flag2 = true;
                    w[b]++;
                    l[a]++;
                }else{
                    flag2 = true;
                    w[a]++;
                    l[b]++;
                }
            }else if(s1 == "scissors"){
                if(s2 == "scissors"){
                    continue;
                }
                else if(s2 == "rock"){
                    flag2 = true;
                    w[b]++;
                    l[a]++;
                }else{
                    flag2 = true;
                    w[a]++;
                    l[b]++;
                }
            }else{
                if(s2 == "paper"){
                    continue;
                }
                else if(s2 == "scissors"){
                    flag2 = true;
                    w[b]++;
                    l[a]++;
                }else{
                    flag2 = true;
                    w[a]++;
                    l[b]++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(!w[i] && !l[i]){
                cout << "-\n";
                continue;
            }
            cout <<fixed << setprecision(3)<< (w[i]/(w[i]+l[i])) << '\n';
        }
    }
}