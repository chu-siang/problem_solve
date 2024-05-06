#include<bits/stdc++.h>
using namespace std;

void update(int q[][9][10],int r, int c,int n){
    int d,r1,c1;
    for(d = 1; d<= 9; d++)
        q[r][c][d]=0;
    for(c1 = 0; c1 < 9; c1++)
        q[r][c1][n] = 0;
    for(r1 = 0; r1 <9;r1++)
        q[r1][c][n] = 0;
    for(r1 = r/3*3;r1 <= r/3*3+2;r1++)
        for(c1=c/3*3;c1 <= c/3*3+2;c1++)
            q[r1][c1][n] = 0;
    q[r][c][n] = 1;
}

void read(int q[9][9][10]){
    ifsteram f;
    f.open("Q1.txt");
    int r,c,d,n;
    for(r = 0; r < 9; r++){
        for(c = 0; c < 9; c++){
            for(d = 1; d <= 9; d++)
                q[r][c][d] = 1;
        }
    }
    for(r = 0; r < 9; r++){
        for(c = 0; c < 9; c++){
            f >> n;
            q[r][c][0] = n;
            if(n>0)update(q,r,c,n);
        }
    }
    f.close();
}
void write(int q[][9][10]){
    int r,c;
    for(r = 0;r<9;r++){
        for(c = 0; c < 9;c++){
            cout << q[r][c][0] << ' ';
        }
        cout << endl;
    }
}
int test(int q[][9][10],int r,int c){
    int count = 0,d,n;
    for(d = 1; d <= 9; d++){
        if(q[r][c][d] == 1){
            count++;
            r= d;
        }
    }
    if(count == 1)return n;
    else return 0;
}

int main(){
    int q[9][9][10];
    read(q);
    int r,c,n,change = 0;
    do{
        change = 0;
        for(r = 0;r<9;r++){
            for(c = 0; c < 9;c++){
                if(q[r][c][0] == 0){
                    n =test(q,r,c);
                    if(n > 0){
                        change = 1;
                        q[r][c][0] = n;
                        update(q,r,c,n);
                    }
                }
            }
        }
    }while(change == 1);
    write(q);
    return 0;
}