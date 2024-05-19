#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[50];
int num[50];
int i;
int Max(){
    int sum = 1;
    for(int m = 0; m < i; m++){
        int n = num[m];
        while(c[m]=='+')n+=num[++m];
        sum*=n;
    }
    return sum;
}
int Min(){
    int sum = 0;
    for(int m = 0; m < i; m++){
        int n = num[m];
        while(c[m] == '*')n*=num[++m];
        sum+=n;
    }
    return sum;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        i = 0;
        stringstream ss(s);
        int a;
        char b;
        while(ss >> a >> b){
            num[i] = a,c[i++] = b;
        }
        num[i++] = a;
        cout << "The maximum and minimum are " << Max() << " and " << Min() <<".\n";
    } 
}