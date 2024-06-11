//uva 10182
#include<bits/stdc++.h>
using namespace std;

int dr[6][2] = {{-1,1},{-1,0},{0,-1},{1,-1},{1,0},{0,1}};


signed main(){
    int x = 0,y = 0;
    int n;

    vector<pair<int,int>>p;
    p.push_back({0,0});
    int round = 1,circle = 0;
    while(p.size() < 100001){
        y++;
        circle = 0;
        p.push_back({x,y});
        while(circle < 6){
            int time = !circle;
            while(time < round){
                x += dr[circle][0];
                y += dr[circle][1];
                p.push_back({x,y});
                time++;
            }
            circle++;
        }
        round++;
    }
    while(cin >> n){
        cout << p[n-1].first << ' ' << p[n-1].second << '\n';
    }
}