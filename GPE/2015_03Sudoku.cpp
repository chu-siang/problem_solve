#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(vector<vector<int>>&v,int x,int y,int val){
    int row = x - x%3, column = y - y%3;
    for(int i = 0; i < 9; i++){
        if(v[i][y] == val)return false;
        if(v[x][i] == val)return false;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(v[row+i][column+j] == val)return false;
        }
    }
    return true;
}
bool build(vector<vector<int>>&v,int i,int j){
    if(i == 9)return true;
    if(j == 9)return build(v,i+1,0);
    if(v[i][j]!=0)return build(v,i,j+1);
    for(int num = 1; num <= 9; num++){
        if(check(v,i,j,num)){
            v[i][j] = num;
            if(build(v,i,j+1))return true;
            v[i][j] = 0;
        }
    }
    return false;
}
signed main(){
    int n;
    cin >> n;
    while(n--){
        vector<vector<int>>v(9,vector<int>(9));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cin >> v[i][j];
            }
        }
        if(build(v,0,0)){
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    cout << v[i][j] << " \n"[j==8];
                }
            }
        }else cout << "NO\n";
    }

}