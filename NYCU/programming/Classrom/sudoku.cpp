#include<bits/stdc++.h>
using namespace std;
// row : 1-9 的row 哪個字用過了
// colunn: 1-9 的column 哪個字用過了
//block 1-9的block 哪個字用過了
int maze[10][10];
bool row[10][10] = {false};
bool column[10][10] = {false};
bool block[10][10]= {false};
// void dfs(int count){
//     if(count == )
// }


int main(){
    fstream f;
    f.open("Q1.txt");
    int cnt = 0;//從1-最後
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            f >> maze[i][j]; 
            int num = maze[i][j];
            cnt++;
            if(num != 0){
                row[i][num-1] = 1;
                column[j][num-1] = 1;
                int r = (i/3)*3 + (i%3),c = (j/3)*3+(j%3);
                int mx = max(r,c);
                block[mx][num-1] = 1;
            }
        }
    }
    // 0 1 2   //0 1 2  /3 * 3 + 2
    // 0 1 2   //3 4 5
    // 0 1 2   /6 7 8
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(!maze[i][j]){
                for(int num = 1; num <= 9; num++){
                    if(row[i][num-1])continue;
                    if(column[j][num-1])continue;
                    if(block[max((i/3)*3 + (i%3),(j/3)*3+(j%3))][num-1])continue;
                    row[i][num-1] = 1, column[j][num-1] = 1;
                    block[max((i/3)*3 + (i%3),(j/3)*3+(j%3))][num-1]=1;
                    maze[i][j] = num;
                    dfs()
                }
            }
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << maze[i][j] << ' ';
        }
        cout << '\n';
    }
    f.close();
}