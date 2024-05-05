#include<bits/stdc++.h>
#define ll long long
using namespace std;

const double pi = acos(0.0)*2.0;

int main(){
    double s,a;
    string str;
    double chord, arc;
    while(cin >> s >> a >> str){
        if(str == "min") a /= 60.0;
        if(a > 180.0) a = 360.0 - a;
        double r = s + 6440.0;
        //arc = 2 pi r* a / 180;
        arc = 2 * pi * r * a /360.0;
        chord = 2 * r * sin(a/2.0 * pi / 180);
        cout << fixed << setprecision(6) << arc << ' ' << chord << '\n'; 
        // chord = 2 * r* sin(a/2 * pi / 180);
    }
}