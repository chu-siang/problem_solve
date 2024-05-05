//uva 11001Necklace
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    double vt,v0;
    while(cin >> vt >> v0){
        if(vt == 0 && v0 == 0)break;
        if(v0 >= vt){
            cout << "0\n";
            continue;
        }else if(vt <= 2*v0){
            cout << "1\n";
            continue;
        }else{
            if(0.5*(vt/v0) - (int)(0.5*(vt/v0)) == 0.5){
                cout << "0\n";
                continue;
            }else if(0.5*(vt/v0) - (int)(0.5*(vt/v0)) < 0.5){
                cout << (int)(0.5*vt/v0) << '\n';
            }else{
                cout << ((int)(0.5*vt/v0)+1) << '\n';
            }
        }
    }
}