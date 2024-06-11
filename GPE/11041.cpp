#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e4+5;

string s[51];
bool cmp(string a,string b){
    return a+b > b+a;
}
signed main(){
    int n;
    while(cin >> n,n){
        for(int i = 0; i < n; i++)cin >> s[i];
        sort(s,s+n,cmp);
        for(int i = 0; i < n; i++)cout << s[i];
        cout << '\n';
    }

}