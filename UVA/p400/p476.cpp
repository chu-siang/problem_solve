#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Point{
    double x1,y1,x2,y2;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vector<Point>v;
    char c;
    Point p;
    while(cin >> c){
        if(c == '*')break;
        cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;
        v.emplace_back(p);
    }
    int C = 1,l = v.size();
    double a,b;
    while(cin >> a >> b){
        if(a == b && a == 9999.9)break;
        bool flag = false;
        for(int i = 0; i < l; i++){
            if(v[i].x1 < a && a < v[i].x2 && v[i].y1 > b && b > v[i].y2){
                cout << "Point " << C << " is contained in figure " << i+1 << '\n';
                flag = true;
            }
        }
        if(!flag)cout << "Point " << C << " is not contained in any figure\n";
        C++;
    }
}