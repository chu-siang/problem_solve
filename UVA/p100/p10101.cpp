#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;


void ban(ull t){
    if(t >= 10000000){
        ban(t / 10000000);
        t %= 10000000;
        cout << " kuti";
    }
    if(t >= 100000){
        ban(t / 100000);
        t %= 100000;
        cout << " lakh";
    }
    if(t >= 1000){
        ban(t / 1000);
        t %= 1000;
        cout << " hajar";
    }
    if(t >= 100){
        ban(t / 100);
        t %= 100;
        cout << " shata";
    }
    if(t > 0){
        cout << " " << t;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ull t;
    ll i = 0;
    while(cin >> t){
        i++;
        cout <<setfill(' ')<<setw(4)<< i << ".";
        if(t == 0){
            cout << " 0\n";
            continue;
        }
        ban(t);
        cout  << '\n';
    }
}
