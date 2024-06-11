//uva 10324 Zeros and ones
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN];
signed main(){
    string s;
    int CASE = 0;
    while(cin >> s){
        if(s == "")break;
        memset(a,0,sizeof(a));
        int t;
        cin >> t;
        for(int i = 1; i <= s.size(); i++){
            a[i]+=a[i-1]+(s[i-1]=='1');
        }
        cout << "Case "<< ++CASE << ":\n";
        while(t--){
            int i,j;
            cin >> i >> j;
            if(i > j)swap(i,j);
            j++,i++;
            if(a[j]-a[i-1] == 0 || a[j] - a[i-1] == j-i+1)cout << "Yes\n";
            else cout << "No\n";
        }
    }
}