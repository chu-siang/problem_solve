#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[55];
void parse(string seq){
    int m = 0;
    int Sign = 1;
    int l = 0;
    char ch;
    for(int i = 1; i < seq.size(); i++){
        if(seq[i] == '-'){
            Sign *= -1;
        }else if(seq[i] <= '9' && seq[i] >= '0'){
           m*=10;
           m+=(seq[i]-'0');
        }else{
            l = i;
            ch = seq[i];
            break;
        }
    }
    m *= Sign;
    if(ch == '+'){
        parse(seq.substr(l+1));
        int d = a[0];
        a[0] = m;
        for(int i = 1; i < 50; i++){
            int t = a[i];
            a[i] = a[i-1]+d;
            d = t;
        }
    }else if(ch == '*'){
        parse(seq.substr(l+1));
        a[0] *= m;
        for(int i = 1; i < 50; i++){
            a[i] *= a[i-1];
        }
    }else{
        for(int i = 0; i < 50; i++)a[i] = m;
    }
}


signed main(){
    
    while(cin >> s){
        memset(a,0,sizeof(a));
        int n;
        cin >> n;
        parse(s);
        for(int i = 0; i < n; i++){
            cout << a[i] << " \n"[i==n-1];
        }
    }

}