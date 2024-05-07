//uva 10209
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    double f;
    double pi = acos(-1);
    while(cin >> f){
        double a,b,c;
        c = f*f - (f*f*pi/6) - (f*f*sqrt(3)/4);
        b = f*f-(f*f*pi)/4-c*2;
        a = f*f-4*b-4*c;
        printf("%.3lf %.3lf %.3lf\n",a,b*4,c*4);
    }
}