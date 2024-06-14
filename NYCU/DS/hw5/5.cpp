//uva10278
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+5;

signed main(){
    int nshop, nintersections;
    cin >> nshop >> nintersections;
    string s;
    stringstream ss;
    vector<vector<int>>weight(nintersections+1,vector<int>(nintersections+1,1e9));
    vector<int>shortest(nintersections+1,0);
    vector<int>shop(nshop);
    for(int i = 0; i < nshop; i++)cin >> shop[i];
    int a,b,w;
    //cin.ignore();
    while(cin >> a >> b >> w){
        weight[a][b]=weight[b][a] = w;
    }
    for(int i = 1; i <= nintersections; i++)weight[i][i] = 0;
    for(int k = 1; k <= nintersections; k++){
        for(int i = 1; i <= nintersections; i++){
            for(int j = 1; j <= nintersections; j++){
                int through = weight[i][k] + weight[k][j];
                if(through < weight[i][j]){
                    weight[i][j] = through;
                }
            }
        }
    }
    int mxlength = 0;
    for(int i = 1; i <= nintersections; i++){
        int dis = 1e9;
        for(int j = 0; j < nshop; j++){
            if(weight[i][shop[j]] < dis){
                dis = weight[i][shop[j]];
            }
        }
        shortest[i] = dis;
        if(dis > mxlength){
            mxlength = dis;
        }
    }
    int intsec = 1;
    for(int i = nintersections; i >= 1; i--){
        int tempmx = 0;
        for(int j = 1; j <= nintersections; j++){
            if(weight[j][i] < shortest[j]){
                if(tempmx < weight[j][i]){
                    tempmx = weight[j][i];
                }
            }else{
                if(tempmx < shortest[j]){
                    tempmx = shortest[j];
                }
            }
        }
        if(tempmx <= mxlength){
            intsec = i;
            mxlength = tempmx;
        }
    }
    cout << intsec << '\n';
}
/*
1 6
2
1 2 10
2 3 10
3 4 10
4 5 10
5 6 10
6 1 10
*/