//a103 uva 573
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    // 深度 , 上升 , 下降 , 疲勞
    // 6 3 1 10
    double h,u,d,f;
    while(cin >> h >> u >> d >> f){
        if(h == 0)break;
        int day = 0;
        double now = 0;
        double fatigue = u*(f/100.0);//第一天疲勞
        bool flag = false;
        while(now < h){
            if(day)u -= fatigue;
            if(u < 1e-6)u = 0;
            now += u;
            day++;
            if(now > h)break;
            now -= d;
            if(now < 0){
                flag = 1;
                break;
            }
        }
        if(!flag)cout << "success on day " << day << '\n';
        else cout << "failure on day " << day << '\n';
    }
}
