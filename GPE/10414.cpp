//Bangla Numbers  uva10101
#include<bits/stdc++.h>
#define int long long
using namespace std;
//10000000 kuti  100000 lakh   1000 hajar 100 shata
//7 5 3 2

void check(int n){
    if(n >= 10000000){
        check(n/10000000);
        n%=10000000;
        cout << " kuti";
    }
    if(n >= 100000){
        check(n/100000);
        n%=100000;
        cout << " lakh";
    }
    if(n >= 1000){
        check(n/1000);
        n%=1000;
        cout << " hajar";
    }
    if(n >= 100){
        check(n/100);
        n%=100;
        cout << " shata";
    }
    if(n)cout << " " << n;
}

signed main(){
    int n;
    int i = 0;
    bool flag = false;
    while(cin >> n){
        cout <<setfill(' ') << setw(4)<< ++i << ".";
        if(n){
            check(n);
            cout << '\n';
        }else cout << " 0\n";
    }
}