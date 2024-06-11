#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[100];
int k,n;
int c;
void f(){
    for(int i = 0; i < k; i++){
        for(int j = i+1; j < k; j++){
            if((c/x[i]%k) == (c/x[j]%k)){
                c = min((c/x[i]+1)*x[i],(c/x[j]+1)*x[j]);
                f();
                return ;
            }
        }
    }
}
signed main(){
    string s;
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--){
        
        getline(cin,s);
        memset(x,0,sizeof(x));
        k = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                k++;
                while(s[i+1] == ' ')i++;
            }else if(s[i] <='z' && s[i]>='a'){
                x[k] = x[k]*32 + s[i]-'a'+1;
            }
        }
        k++;
        sort(x,x+k);
        c = x[0];
        f();
        cout << s << '\n' << c << '\n' << '\n';
    }
}