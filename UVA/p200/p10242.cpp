#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    double x1,x2,x3,y1,y2,y3;
    double x[4],y[4];
    while(cin >> x[0] >> y[0]){
        for(int i = 1; i < 4; i++)cin >> x[i] >> y[i];
        if(x[0] == x[2] && y[0] == y[2]){
            x1 = x[1],y1 = y[1];
            x2 = x[0],y2 = y[0];
            x3 = x[3],y3 = y[3];
        }else if(x[0] == x[3] && y[0] == y[3]){
            x1 = x[1],y1 = y[1];
            x2 = x[0],y2 = y[0];
            x3 = x[2],y3 = y[2];
        }else if(x[1] == x[2] && y[1] == y[2]){
            x1 = x[0],y1 = y[0];
            x2 = x[1],y2 = y[1];
            x3 = x[3],y3 = y[3];
        }else if(x[1] == x[3] && y[1] == y[3]){
            x1 = x[0],y1 = y[0];
            x2 = x[1],y2 = y[1];
            x3 = x[2],y3 = y[2];
        }
        cout << fixed << setprecision(3) << x3 + x1 - x2 << ' ' << y3 + y1 - y2 << '\n';
    }
    
    return 0;
}

