//uva 10002 不常考
#include<bits/stdc++.h>
using namespace std;
struct pt{
    double x,y;
    pt operator-(const pt &other) const{
        return (pt){x - other.x,y - other.y};
    }
}p[101];
pt s;
double cross(pt a,pt b){
    return a.x * b.y - a.y * b.x;
}
bool cmp(pt a,pt b){
    if (cross(a - s,b - s) <= 0)
        return false;
    return true;
}
int main(){
    int n;
    while (cin >> n && n >= 3){
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        s.x = p[0].x,s.y = p[0].y;
        sort(p + 1,p+n,cmp);
        double sx, sy, sa;
        sx = sy = sa = 0;
        for (int i = 2; i < n; i++)
        {
            double a = cross(p[i - 1] - s,p[i] - s) * 0.5;
            sa += a;
            sx += (p[0].x + p[i - 1].x + p[i].x) * a;
            sy += (p[0].y + p[i - 1].y + p[i].y) * a;
        }
        printf("%.3f %.3f\n",sx / sa / 3,sy / sa / 3);
    }
}