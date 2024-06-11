//uva 991
#include<bits/stdc++.h>
using namespace std;
int c[25][25];
signed main(){
    for(int i = 0; i < 25; i++){
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for(int i = 2; i < 25; i++){
        for(int j = 1; j < i; j++){
            c[i][j] = c[i-1][j]+c[i-1][j-1];
        }
    }
    int n;
    bool flag=false;
    while(cin >> n){
        if(flag)cout << '\n';
        flag = true;
        cout << c[2*n][n]/(n+1) << '\n';
    }
}