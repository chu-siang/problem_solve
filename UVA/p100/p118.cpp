#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m;
    cin >> n >> m;
    ll x,y,d;
    char dc;
    string s;
    bool scent[55][55] = {false};
    char dir[5] = {'N','E','S','W'};
    pair<ll,ll> dis[5];
    dis[0].first = 0, dis[0].second = 1;
    dis[1].first = 1, dis[1].second = 0;
    dis[2].first = 0, dis[2].second = -1;
    dis[3].first = -1, dis[3].second = 0;
    while(cin >> x >> y >> dc){
        switch(dc){
            case 'N': d = 0; break;
            case 'E': d = 1; break;
            case 'S': d = 2; break;
            case 'W': d = 3; break;
        }
        cin >> s;
        int l = s.length();
        bool lost = false;
        for(int i = 0; i < l; i++){
            if(s[i] == 'L')d = (d-1+4)%4;
            else if(s[i] == 'R') d = (d + 1)%4;
            else{
                x += dis[d].first;
                y += dis[d].second;
                if(x > n || y > m || x < 0 || y < 0){
                    x -= dis[d].first;
                    y -= dis[d].second;
                    if(!scent[x][y]){
                        scent[x][y] = true;
                        lost = true;
                        break;
                    }
                }
            } 
        }
        if(!lost){
            cout << x << " " << y <<" "<< dir[d] << '\n';
        }else cout << x << " " << y <<" "<< dir[d] << " LOST\n";
    }

    return 0;
}