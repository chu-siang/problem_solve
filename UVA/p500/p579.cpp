#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    char c;
    double h,m;
    while(cin >> h >> c >> m){
        if(h == 0.0&& m == 0.00)break;
        double deg1 = h*30+m*0.5; //比兩個指針間的夾角 時針角度會因為分針多而變大故*(min/60)*一小時30度
        double deg2 = m*6;//分針 一格 6 度
        double ans = abs(deg1-deg2);
        ans = min(ans,360-ans);
        cout << fixed << setprecision(3) << ans << '\n';
    }
}