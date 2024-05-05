//uva10849
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int c;
    cin >> c;
    while(c--){
        int t;
        cin >> t;
        long long n;
        cin >> n;
        ll x1,x2,y1,y2;
        for(int i = 0; i < t; i++){
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 == x2 && y1 == y2) cout << "0\n";
            else if(abs(x2-x1) == abs(y2-y1)) cout << "1\n";
            // 把座標當籌碼的概念
            else if((abs(x2-x1)&1) == (abs(y2-y1)&1)) cout << "2\n";
            else cout << "no move\n";
        }
    }
}